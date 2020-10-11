#include <iostream>

int sum(int a, int b = 0) { return a + b; }

// int sum(int x) {return x};

int main(void) {
  // std::cout << sum(5, 10) << std::endl;
  std::cout << sum(5) << std::endl;
  // std::cout << sum() << std::endl;
  return 0;
}

