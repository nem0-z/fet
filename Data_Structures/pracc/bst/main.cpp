#include <iostream>
#include "bst.hpp"

int main(void) {
  set<int> s;
  s.insert(7);
  s.insert(4);
  s.insert(5);
  s.insert(3);
  s.insert(1);
  s.insert(2);
  // s.insert(20);
  // s.insert(16);
  s.print();
  s.erase(2);
  s.print();
}

//     40
//   30  50
// 4  17
//
//
