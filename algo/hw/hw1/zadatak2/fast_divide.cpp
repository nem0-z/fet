#include <iostream>

int pow(int x, int y) {
  int i = 1;
  while (x >= y) {
    y <<= 1;
    ++i;
  }
  return i - 2;
}

int fast_divide(int x, int y) {
  if (y == 0)
    throw std::logic_error("Division with 0");
  else if (x == y)
    return 1;
  // 10/10 = 1;
  else if (x < y)
    return 0;
  // 8/10 = 0;
  int power = pow(x, y);
  int yShift = y << power;
  int ones = 1 << power;
  if (x == yShift) return ones;
  return ones + fast_divide(x - yShift, y);
}

int main(void) {
  std::cout << fast_divide(32, 8) << std::endl;
  std::cout << fast_divide(3, 1) << std::endl;
  std::cout << fast_divide(3, 6) << std::endl;
  std::cout << fast_divide(25, 4) << std::endl;
  std::cout << fast_divide(25, 5) << std::endl;
  std::cout << fast_divide(24, 6) << std::endl;
  std::cout << fast_divide(24, 24) << std::endl;
  std::cout << fast_divide(19, 4) << std::endl;
  return 0;
}
