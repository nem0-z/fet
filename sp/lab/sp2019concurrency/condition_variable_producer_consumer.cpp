#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

struct Element {};
atomic<int> num_consumed{0}, num_produced{0};

Element produce_element() {
  ++num_produced;
  return Element{};
}

void consume_element(Element&& el) { ++num_consumed; }

atomic<bool> done{false};
const int MAX = 10;
queue<Element> buffer;
mutex queue_mtx;
condition_variable produce_cv;
condition_variable consume_cv;

void producer() {
  while (!done) {
    Element el = produce_element();
    {
      unique_lock<mutex> lck(queue_mtx);
      // produce_cv.wait(lck, []() { return buffer.size() < MAX; });
      while(buffer.size() == MAX){
        if(done) return;
        produce_cv.wait(lck);
      }

      buffer.emplace(move(el));
    }
    consume_cv.notify_one();
  }
}

void consumer() {
  Element el;
  while (!done) {
    {
      unique_lock<mutex> lck(queue_mtx);
      // consume_cv.wait(lck, []() { return !buffer.empty(); });
      while(buffer.empty()){
        if(done) return;
        consume_cv.wait(lck);
      }
      el = move(buffer.back());
      buffer.pop();
    }
    produce_cv.notify_one();
    consume_element(move(el));
  }
}

int main(int argc, char* argv[]) {
  thread t1{producer};
  thread t2{consumer};
  thread t3{producer};
  thread t4{consumer};
  this_thread::sleep_for(chrono::seconds{5});
  done = true;
  produce_cv.notify_all();
  consume_cv.notify_all();
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  std::cout << buffer.size() << " " << num_produced << " " << num_consumed
            << endl;
  return 0;
}
