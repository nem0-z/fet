#include <iostream>
#include "heap.hpp"

int main(int argc, char *argv[])
{
 heap<int> h;
 h.insert(5);
 h.insert(3);
 h.insert(1);
 h.insert(10);
 h.print();
 std::cout << h.size() << std::endl;
 h.pop();
 h.print();
 std::cout << h.size() << std::endl;
 h.pop();
 h.print();
 std::cout << h.size() << std::endl;
 h.pop();
 h.print();
 std::cout << h.size() << std::endl;
 h.pop();
 h.print();
 std::cout << h.size() << std::endl;
 h.insert(1);
 h.insert(3);
 h.insert(15);
 h.insert(7);
 h.print();
 std::cout << h.size() << std::endl;
 h.pop();
 h.print();
 std::cout << h.size() << std::endl;
 h.insert(4);
 h.print();
 std::cout << h.size() << std::endl;
  return 0;
}
