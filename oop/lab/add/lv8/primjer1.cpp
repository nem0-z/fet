#include <iostream>
#include "cplx.hpp"

int main(void) {
  LV8::cplx number1, number2;
  std::cout << "Unesite realni dio prvog broja: ";
  std::cin >> number1.re;
  std::cout << "Unesite imaginarni dio prvog broja: ";
  std::cin >> number1.im;

  std::cout << "Unesite realni dio drugog broja: ";
  std::cin >> number2.re;
  std::cout << "Unesite imaginarni dio drugog broja: ";
  std::cin >> number2.im;

  auto result = LV8::sum(number1, number2);
  std::cout << "Rezultat: ";
  LV8::print(result);

  return 0;
}
