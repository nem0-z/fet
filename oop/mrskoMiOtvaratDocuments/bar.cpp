#include <iostream>

using namespace std;

struct A {
  A() = default;
  // A(const A &) : x{6} { std::cout << 1 << std::endl; }
  A(const A &&) : x{7} { std::cout << 4 << std::endl; }
  // A(A &&) : x{5} { std::cout << 2 << std::endl; }
  void print() const { std::cout << 3 << std::endl; }
  // ~A() { std::cout << "D" << x << std::endl; }
  int x = 0;
};

void foo(const A &a) {
  A a3(std::move(a));
  a.print();
}

int main(int argc, char *argv[]) {
  A a1;
  foo(a1);
  return 0;
}
