#include <iostream>
#include "set.hpp"

int main(int argc, char *argv[])
{
  set<int> s;
  s.insert(5);
  s.insert(3);
  s.insert(1);
  s.insert(7);
  s.insert(4);
  s.insert(1);
  s.print();
  // std::cout << std::boolalpha << s.find(-235) << std::endl;
  // s.clear();
  // std::cout << std::boolalpha << s.empty() << std::endl;
  s.erase(4);
  s.print();
  set<int> s1(s);
  s1.print();
  set<int> s2;
  s2 = s1;
  s2.print();
  s1 = std::move(s2);
  s2.print();
  s1.print();
  return 0;
}
