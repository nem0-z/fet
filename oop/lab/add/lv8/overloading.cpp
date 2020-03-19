#include <iostream>
#include <string>

void print(int a) { std::cout << a << std::endl; }

void print(std::string a) { std::cout << a << std::endl; }

void test(char a) { std::cout << a << std::endl; }

void test(double a) { std::cout << a << std::endl; }

int main(void) {
  print(5);

  std::string s{"Text"};
  print(s);

  print(5.5);

  test(5.6);
  // test(5);

  return 0;
}
