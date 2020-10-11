#include <iostream>

int main(void) {
  int a = 5;
  int& b = a;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "##################" << std::endl;
  b = 20;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "##################" << std::endl;
  const int& c = a;

  std::cout << "c = " << c << std::endl;

  // Naredne linije nisu validne!
  // c = 20;
  // int& x;
  // const int& y;
  return 0;
}
