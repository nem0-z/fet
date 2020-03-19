#include <iostream>
#include <string>
using std::string;
bool input(string& s1, string& s2) {
  std::cout << "Insert first word: ";
  std::cin >> s1;
  std::cout << "Insert second word: ";
  std::cin >> s2;
  if (s1.size() == s2.size())
    return true;
  else {
    std::cout << "Strings must have equal length,"
              << " try again!" << std::endl;
    return input(s1, s2);
  }
}
void hamming(const string& s1, const string& s2) {
  short hamming = 0;
  for (auto i = 0; i < s1.size(); ++i) {
    if ((s1[i] == (s2[i] + 32) || (s1[i] == (s2[i] - 32)))) continue;
    if (s1[i] != s2[i]) ++hamming;
  }
  std::cout << "Hamming distance: " << hamming << std::endl;
}

int main(void) {
  string s1, s2;
  if (input(s1, s2)) hamming(s1, s2);
  return 0;
}
