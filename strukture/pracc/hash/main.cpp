#include <iostream>
#include "HASHHASHHASH.hpp"

int main(int argc, char *argv[]) {
  hashTable<int, std::string> h;
  h.insert(std::make_pair(5, "Zlatan"));
  std::cout << h[5] << std::endl;
  return 0;
}
