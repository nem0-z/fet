#include <iostream>
#include "bst.hpp"

int main(void) {
  set<int> s;
  s.insert(40);
  s.insert(30);
  s.insert(50);
  s.insert(35);
  s.insert(2);
  s.insert(55);
  s.insert(33);
  s.print();
  // std::cout << s.find(15) << std::endl;
  // std::cout << s.find(4) << std::endl;
  // std::cout << s.find(15) << std::endl;
  // s.insert(150);
  s.print();
  s.erase(40);
  s.print();
  set<int> d = s;
  d.print();
  std::cout << d.size() << std::endl;
  return 0;
  s.print();
}

//     40
//   30  50
// 4  17
//
//
