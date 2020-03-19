#include <iostream>

using namespace std;

void showMe(int a) //call by value, different adress
{
  std::cout << &a << std::endl;
  std::cout << a << std::endl;
}

const int k = 10;

int main(void)
{
  int a = 5;
  int* pa = &a;
  std::cout << pa << std::endl;
  std::cout << *pa << std::endl;
  showMe(a); // (1)
  std::cout << &k << std::endl;
  std::cout << k << std::endl;
  showMe(k); // (2)
  //compare adress of (1) and (2), why are they same?
  int* dummy_pointer = nullptr; //not pointing to anything
  // *dummy_pointer = 10; //undefined
  
  return 0;
}
