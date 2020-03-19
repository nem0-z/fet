#include <iostream>
#include <string>

using namespace std;

struct A {
  int nrA = 0;
  A() = default;
  A(int nr) : nrA{nr} {}
  virtual ~A() { std::cout << "A destructor: " << nrA << std::endl; }
  // ~A() { std::cout << "A destructor: " << nrA << std::endl; }
  virtual void foo() { std::cout << "A" << std::endl; }
};

struct B : A {
  A x{5};
  double nrB = 0;
  B() {
    nrB = 10;
    nrA = 20;
  }
  ~B() override { std::cout << "B destructor" << std::endl; }
  void foo() override { std::cout << "B" << std::endl; }
};

int main(int argc, char* argv[]) {
  A a;
  B b;
  std::cout << "A::a: " << a.nrA << std::endl;
  std::cout << "B::b: " << b.nrB << std::endl;
  // a.foo();
  // b.foo();
  // A* ptrA = &b;
  // ptrA->foo();
  // a = std::move(b);
  // std::cout << "A::a: " << a.nrA << std::endl;
  // std::cout << "B::b: " << b.nrB << std::endl;
  B* heapPtrB = new B{};
  A* heapPtrA = heapPtrB;
  delete heapPtrA;  // undefined/crash if non-virtual destructor in base class
  // even though heapPtrA is of struct B now, it's still pointing to it's
  // superclass
  return 0;
}
