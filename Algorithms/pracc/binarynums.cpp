#include <iostream>

void printBinary(std::string& s, int limit, int ones) {
  if (limit == 0 && ones == 2) {
    std::cout << s << std::endl;
  }
  if (limit == 0) return;
  s.push_back('0');
  printBinary(s, limit - 1, ones);
  s.pop_back();
  if (ones < 2) {
    s.push_back('1');
    printBinary(s, limit - 1, ones + 1);
    s.pop_back();
  }
}

int main(int argc, char* argv[]) {
  std::string s;
  printBinary(s, 8, 0);
  return 0;
}
