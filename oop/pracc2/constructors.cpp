#include <iostream>

struct A {
  A() { std::cout << 1 << std::endl; }
  A(int a) : aPolje{a} { std::cout << "Int" << std::endl; }
  A(const A&) { std::cout << 2 << std::endl; }
  A(A&&) { std::cout << 3 << std::endl; }
  A& operator=(const A&) { std::cout << 4 << std::endl; }
  A& operator=(A&&) { std::cout << 5 << std::endl; }
  virtual ~A() { std::cout << "Unistavam A" << aPolje << std::endl; }
  int aPolje = 0;
};

struct B : A {
  B() { std::cout << 3 << std::endl; }
  B(const B& o) { std::cout << 4 << std::endl; }
  ~B() {
    delete[] bPolje;
    std::cout << "Unistavam B" << std::endl;
  }
  int* bPolje = new int[300000];
};

A foo(bool x) {
  A y{5},z{6};
  if(x) return y;
  else return z;
}

int main(void) {
  // B foo;
  // A* ptr = new B{};
  // *ptr = foo;
  // delete ptr;
  // A x{};
  // A* ptr = new A{};
  // *ptr = x;
  // *ptr = A{};
  // ptr = &x;
  // delete ptr;
  A bar;
  bar = foo(1);
  return 0;
}
