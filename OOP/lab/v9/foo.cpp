#include <iostream>
#include <vector>
void foo(int a)
{
  static int b;
  ++b;
  std::cout << b << std::endl;
}

void foo(double a)
{
  static int b;
  ++b;
  std::cout << b << std::endl;
}

template<class T>
void foo(T a)
{
  static int b;
  ++b;
  std::cout << b << std::endl;
}

int main(int argc, char *argv[])
{
  foo(5.5);
  foo("abc");
  foo("abcac");
  std::vector<char> v;
  foo(v);
  return 0;
}
