#include <iostream>
void input(int& a, int& b, int& c) {
  std::cout << "Enter 3 values: ";
  std::cin >> a >> b >> c;
}
void checkPyth(const int& a, const int& b, const int& c) {
  if ((a * a + b * b == c * c) || (b * b + a * a == c * c) ||
      (b * b + c * c == a * a) || (c * c + b * b == a * a) ||
      (a * a + c * c == b * b) || (c * c + a * a == b * b))
    std::cout << "Those values are sides of right triangle! " << std::endl;
  else
    std::cout << "Those values are not sides of right triangle! " << std::endl;
}
void checkCombo(void) {
  int x;
  std::cout << "Enter limit: ";
  std::cin >> x;
  std::cout << "Possible combinations for a right triangle: " << std::endl;
  for (auto i = 1; i <= x; ++i) {
    for (auto b = 1; b < i; ++b) {
      for (auto a = 1; a < b; ++a) {
        if (i * i == a * a + b * b) {
          std::cout << "(" << a << "," << b << "," << i << ")" << std::endl;
        }
      }
    }
  }
}
int main(void) {
  int a, b, c;
  input(a, b, c);
  checkPyth(a, b, c);
  checkCombo();
  return 0;
}
