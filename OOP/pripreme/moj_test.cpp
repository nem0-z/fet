#include <iostream>

struct A {
  private:
  int x = 0;
  int y = 5;

  public:
  A() { std::cout << "A def" << std::endl; }
  A(double a) {x = a; std::cout << "A double " << std::endl; }
  A(const A&) { std::cout << "A copy " << std::endl; }
  ~A() { std::cout << "A destruct " << x<< std::endl; }
  A& operator=(const A&) {
    x = 3;
    y = 6;
    return *this;
  }
};

struct B {
  private:
  int k ;
  A x{5.5};

  public:
  B(double a) : k{a} { std::cout << "B int\t" << k << std::endl; }
  B() { std::cout << "B default" << std::endl; }
  B(const B&) = default;
  ~B() { std::cout << "B destruct" << std::endl; }
};

struct C {
  private:
  B trick;

  public:
  C() { std::cout << "C default" << std::endl; }
  ~C() { std::cout << "C destruct" << std::endl; }
  C(const C&) { std::cout << "C copy" << std::endl; }
};

void fun(const C x) { std::cout << "Funkcija fun" << std::endl; }

int main(void) {
  B bar(5.5);
  // auto x = C{};
  // fun(C{});
  return 0;
}
