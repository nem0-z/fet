#include <iostream>
#include <queue>
#include "heap.hpp"

int main(void) {
  std::priority_queue<int> h;
  h.push(5);
  h.push(16);
  h.push(2);
  h.push(1);
  h.push(10);
  h.push(70);
  std::cout << h.top() << std::endl;
  h.pop();
  std::cout << h.top() << std::endl;
  h.pop();
  return 0;
}
