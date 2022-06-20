#include <future>
#include <thread>
#include <iostream>
#include <chrono>

int foo(int a) { 
  std::cout << "Foo nit: " << std::this_thread::get_id() << std::endl;
  return a; }

int bar(int a) { 
  std::this_thread::sleep_for(std::chrono::microseconds{100});
  std::cout << "Bar nit: " << std::this_thread::get_id() << std::endl;
  return a; }

int main() {
    std::future<int> result1{std::async(std::launch::deferred, foo, 10)};
    int result2 = bar(5);
    int result = result1.get() + result2;
    std::cout << result << std::endl;
}
