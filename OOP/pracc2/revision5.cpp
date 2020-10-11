#include <iostream>
#include <string>
struct A {
  A(int a) : x{a} {}
  ~A() { std::cout << "Destruct" << x << std::endl; }
  int x{};
};

int main(void) {
  A{1};
  A y{4};
  // A y;
  // A x = y;
  // A z = A{2};
  std::string s = "sinisa";
  for (auto i = 0; i < s.size() / 2; ++i) std::swap(s[i], s[s.size() - i - 1]);
  std::cout << s << std::endl;
  return 0;
}
