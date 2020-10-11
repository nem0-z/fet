#include <iostream>

using namespace std;

struct A {
  virtual void f1() {
    x = 5;
    foo();
  }

  void foo() { std::cout << "A" << std::endl; }
  virtual ~A() { std::cout << "~A" << std::endl; }

  protected:
  int x;
};

struct B : A {
  void f1() { foo(); }
  void foo() { std::cout << "B" << std::endl; }
  ~B() { std::cout << "~B" << std::endl; }
};

int main(void) {
  A dummy;
  A* a = new B{};
  a->f1();
  delete a;
  // a = &dummy;
  // a->f1();
  return 0;
}
