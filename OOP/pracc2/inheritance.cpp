#include <iostream>
#include <string>
using namespace std;

struct A {
  int a;
  string b;

  A(int nr) : a{nr} { std::cout << "A constructor" << std::endl; }
  virtual ~A() { std::cout << "A destructor" << std::endl; }

  virtual void print() { std::cout << "A" << std::endl; }

  private:
  int privatni = 0;
};

struct B : A {
  B() : A(5) { std::cout << "B constructor" << std::endl; }
  ~B() { std::cout << "B destructor" << std::endl; }

  size_t c;
  void print() override { std::cout << "B" << std::endl; }
  // keyword override is not needed, we just use it so we can easily distinguish
  // functions that are definitions of virtual functions inside superclass
};

int main(void) {
  A* a = new A(5);
  B* b = new B();  // check constructor in B, what happens if we
  // compiler implicitly create default constructor

  // foo->a = 5;
  // foo->b = "test";
  // foo.privatni = 5; //not accessible obviously
  // a->print();
  // b->print();
  // a = b;
  // a->print();  // calls function in A unless virtual(overload vs override)
  delete b;
  delete a;  // added these two lines since objects on heap won't be deleted at
             // the end of program
  return 0;
}
