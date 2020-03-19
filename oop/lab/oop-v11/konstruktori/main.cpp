#include <iostream>
#include <vector>

class B {
  public:
  B() { std::cout << "B default" << std::endl; }
  B(double) { std::cout << "B double" << std::endl; }
  B(int) { std::cout << "B int" << std::endl; }
  ~B() { std::cout << "B dtor" << std::endl; }
};

class A {
  public:
  explicit A(int a) : b{a} { std::cout << "A int" << std::endl; }

  A(const A&) { std::cout << "Copy ctor" << std::endl; }

  ~A() { std::cout << "A dtor" << std::endl; }

  void print() { std::cout << "print" << std::endl; }

  private:
  B b;
};

void foo(const A& a) { std::cout << "foo A" << std::endl; }

int main(int argc, char* argv[]) {
  foo(A( 7 ));
  return 0;
}
