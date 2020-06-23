#include <iostream>
#include "stack.hpp"

int main(int argc, char *argv[])
{
  stack<int> s;
  s.push(5);
  s.push(14);
  s.push(10);
  s.push(7);
  std::cout << s.top() << std::endl;
  stack<int> s2(s);
  std::cout << s2.top() << std::endl;
  return 0;
}
