#include <iostream>
#include "Cplx.hpp"

int main(void) {
  Cplx cp1(1, 1), cp2(2, -3);
  std::cout << "Cp1: " << cp1 << std::endl;
  std::cout << "Cp2: " << cp2 << std::endl;
  
  std::cout << "operator+: " << std::endl;
  auto cp3 = cp1 + 5;
  std::cout << "Cp1: " << cp1 << std::endl;
  std::cout << "Cp3: " << cp3 << std::endl;
  
  std::cout << "operator+=: " << std::endl;
  cp2 += 20;
  std::cout << "Cp2: " << cp2 << std::endl;

  std::cout << "operator-: " << std::endl;
  auto cp4 = cp2 - 5;
  std::cout << "Cp2: " << cp2 << std::endl;
  std::cout << "Cp4: " << cp4 << std::endl;
  
  std::cout << "operator-=: " << std::endl;
  cp1 -= 20;
  std::cout << "Cp1: " << cp1 << std::endl;

  return 0;
}
