#include <iostream>

using ull = unsigned long long;

ull multiplyEven(int limit) {
  if(limit%2 == 1) --limit;
  if(limit<2) return 0;
  if(limit==2) return (ull)limit;
  return (ull)limit * multiplyEven((ull)limit - 2);
}

int main(void) {
  int limit;
  std::cin >> limit;
  std::cout << multiplyEven(limit) << std::endl;
  return 0;
}
