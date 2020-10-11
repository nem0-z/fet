#include <iostream>
#include "binary_tree.hpp"

int main(void) {
  binary_tree<int> b;
  b.add(20);
  b.add(10);
  b.add(25);
  b.add(15);
  b.add(8);

  b.print();

  std::cout << std::boolalpha << b.find(10) << std::endl;
  std::cout << std::boolalpha << b.find(11) << std::endl;
  return 0;
}
