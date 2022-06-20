#include <iostream>
#include <thread>
void foo(int& i) { ++i; }
int main() {
  int a = 5;
  std::thread t{foo, std::ref(a)};
  t.join();
  std::cout << "a: " << a << std::endl;
}
