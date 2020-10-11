#include <iostream>
#include <string>


template <class It1, class It2>
bool jednako(It1 start1, It1 end, It2 start2) {
  while (start1 != end) {
    if (*start1++ != *start2++) return false;
  }
  return true;
}

int main(void)
{
  std::string test;
  while (std::cin >> test) {
    std::string temp;
    for (auto it = --test.end(); it != --test.begin(); --it)
      temp.push_back(*it);
    if (jednako(test.begin(), test.end(), temp.begin()))
      std::cout << test << " je palindrom!" << std::endl;
  }
  return 0;
}
