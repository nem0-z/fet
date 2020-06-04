#include <iostream>
#include "heap.hpp"

int main(int argc, char *argv[]) {
  heap<int> h{1,3,5,7,9,11,2};
  h.print();
  return 0;
}
