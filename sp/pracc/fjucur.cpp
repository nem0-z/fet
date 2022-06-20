#include <bits/stdc++.h>

template <typename T> class Stack {
public:
  void push(const T &el) {
    std::unique_lock<std::mutex> lg(m_);
    stack_.push(el);
    lg.unlock();
    cv_.notify_one();
  }

  int size() {
    std::lock_guard<std::mutex> lg(m_);
    return stack_.size();
  }

  T pop() {
    std::unique_lock<std::mutex> lck(m_);
    while (stack_.empty()) {
      std::cout << "zaglavio sam ovdjeeee" << std::endl;
      cv_.wait(lck);
    }

    T el = stack_.top();
    stack_.pop();
    return el;
  }

private:
  std::stack<T> stack_;
  std::mutex m_;
  std::condition_variable cv_;
};

Stack<int> stack;

void push_chunk() {
  for (int i = 0; i < 1000; i++) {
    stack.push(i);
  }
}

void pop_chunk() {
  for (int i = 0; i < 1000; i++) {
    stack.pop();
  }
}

int pop_one() { return stack.pop(); }

int main(int argc, char *argv[]) {
  std::vector<std::thread> pushers;
  std::vector<std::thread> poppers;
  std::vector<std::future<int>> futures;

  for (int i = 0; i < 4; ++i) {
    pushers.push_back(std::thread{push_chunk});
  }

  for (int i = 0; i < 4; ++i) {
    poppers.push_back(std::thread{pop_chunk});
    // futures.push_back(std::async(std::launch::async, pop_one));
  }

  for (auto &t : pushers) {
    t.join();
  }

  for (auto &t : poppers) {
    t.join();
  }
  // while (stack.size() > 0) {
  //   std::thread t(pop_chunk);
  //   t.join();
  // }

  std::cout << stack.size() << std::endl;
}
