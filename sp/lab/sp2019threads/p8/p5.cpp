#include <iostream>
#include <thread>
int main() {
  int a = 5;
  std::thread t{[&a](int b) { a += b; }, 10};
  t.join();
  std::cout << "a: " << a << std::endl;
}
