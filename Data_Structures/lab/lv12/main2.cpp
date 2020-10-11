#include <algorithm>
#include <iostream>
#include <vector>

void printHeap(const std::vector<int>& h) {
  for (const auto& item : h) std::cout << item << " ";
  std::cout << std::endl;
}

int main(void) {
  std::vector<int> h;
  h.push_back(5);
  h.push_back(16);
  h.push_back(2);
  h.push_back(1);
  h.push_back(10);
  h.push_back(70);
  std::cout << "Before heapify:" << std::endl;
  printHeap(h);
  std::make_heap(h.begin(), h.end());
  std::cout << "After heapify:" << std::endl;
  printHeap(h);
  std::pop_heap(h.begin(),h.end());
  std::cout << "Max: " << h.back() << std::endl;
  h.pop_back();
  // std::cout << h.front() << std::endl;
  h.push_back(50);
  std::push_heap(h.begin(), h.end());
  h.push_back(20);
  std::push_heap(h.begin(), h.end());
  printHeap(h);
  return 0;
}
