#include <iostream>
#include<string>
#include<vector>
struct A {
  virtual void foo() = 0;
};
struct B : A {
  void foo() { std::cout << "B" << std::endl; }
};
struct C : B {
  void foo() { std::cout << "C" << std::endl; }
};

struct T{
  int foo = 0;
  int& getFoo() {return foo;}
  void printFoo() {std::cout<<foo;}
};

int y(int&) { return 1; }
int y(int&&) { return 2; }
int f(int x) { return y(x); }
int g(int x) { return y(std::move(x)); }

int main() {
  // A* p = new C{};
  // A a = *p;
  // a.foo();
  // int i = 10;
  // std::cout << f(10) << f(5) << std::endl;
  // std::cout << g(10) << g(5) << std::endl;
//   T a;
//   auto bar = a.getFoo();
//   ++bar;
//   a.printFoo();
// std::cout<<std::string{"ABCDE"}.size()<<std::endl;
try{
  int x = 10;
  throw x;
}
catch(const int y)
{
  return 1;
}
  return 0;
}
