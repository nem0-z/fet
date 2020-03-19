#include <iostream>
#include <string>

void foo(int a)
{
  std::cout << 2 << std::endl; 
}
// void foo(double a)
// {
//   std::cout << 3 << std::endl;
// }
void foo(char a)
{
  std::cout << 3 << std::endl;
}

int main()
{
  foo(5.5);
  return 0;
}
