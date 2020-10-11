#include <iostream>

using namespace std;

void foo(int x) { std::cout << &x << std::endl; }

void foo(int* ptr) {
  if (ptr != nullptr) std::cout << *ptr << std::endl;
}

int main(void) {
  int a;
  std::cout << &a << std::endl;
  foo(a);
  int* pa = &a;
  std::cout << pa << std::endl;
  *pa = 400;
  std::cout << a << std::endl;
  foo(pa);
  foo(&a);  // ovo dvoje je isto
  // osim sto kad radis s pointerima, on moze biti uninitialized pa napravit
  // belaj reference ce uvijek imati adresu neku logyyyyyyy
  return 0;
}
