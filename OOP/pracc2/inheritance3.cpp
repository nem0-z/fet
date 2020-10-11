#include <iostream>

struct myInterface {
  virtual void foo() = 0;
  ~myInterface() {}
};

struct Foo : myInterface {
  void foo() { std::cout << "Foo" << std::endl; }
  ~Foo() { std::cout << "Foo destructing" << std::endl; }
};

struct Bar : Foo {
  void foo() { std::cout << "Bar" << std::endl; }
  ~Bar() { std::cout << "Bar destructing" << std::endl; }
};

int main(int argc, char* argv[]) {
  Foo* poly = new Bar{};
  poly->foo();
  return 0;
}
