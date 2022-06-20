#include <atomic>
#include <thread>
#include <iostream>

using std::atomic;

void foo(std::shared_ptr<atomic<int>> p, int num) {
  for(int i = 0; i < num; ++i)
    ++*p;
}

int main() {
  auto ptr = std::make_shared<atomic<int>>(0);
  std::thread t1{ foo, ptr, 50000};
  std::thread t2{ foo, ptr, 10000};
  t1.join();
  t2.join();
  std::cout << "val: " << *ptr << " count: " << ptr.use_count() << std::endl;
}
