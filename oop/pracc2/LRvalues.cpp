#include <iostream>

using namespace std;

int main(void)
{
  int&& x = 5;
  int&& y = 10;
  std::cout << x<<y << std::endl;
  x+=4;
  y = 5;
  std::cout << x <<y<< std::endl;
  return 0;
}
