#include "heap.hpp"

int main(void)
{
  heap<int> h;
  h.insert(5);
  h.insert(16);
  h.insert(2);
  h.insert(1);
  h.insert(10);
  h.insert(70);
  h.printHeap();
  std::cout << h.extractMax() << std::endl;
  std::cout << h.extractMax() << std::endl;
  h.printHeap();
  return 0;
}
