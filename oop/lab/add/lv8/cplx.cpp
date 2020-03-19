#include "cplx.hpp"
#include <iostream>

void LV8::print(const LV8::cplx& c) {
  std::cout << c.re << " + " << c.im << "i" << std::endl;
}

LV8::cplx LV8::sum(const LV8::cplx& first, const LV8::cplx& second) {
  LV8::cplx result;
  result.re = first.re + second.re;
  result.im = first.im + second.im;
  return result;
}
