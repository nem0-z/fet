#include <iostream>

int divide(int x, int y) {
  if (y == 0)
    throw std::logic_error("Division with 0.");
  else if (x == y)
    return 1;
  else if (x < y)
    return 0;
  return 1 + divide(x - y, y);
}

int main(void) {
  std::cout << divide(6, 2) << std::endl;
  std::cout << divide(24, 8) << std::endl;
  std::cout << divide(24, 7) << std::endl;
  std::cout << divide(25, 5) << std::endl;
  std::cout << divide(2, 1) << std::endl;
  std::cout << divide(1, 1) << std::endl;
  std::cout << divide(1, 4) << std::endl;
  std::cout << divide(0, 4) << std::endl;
  std::cout << divide(498, 13) << std::endl;
  return 0;
}

