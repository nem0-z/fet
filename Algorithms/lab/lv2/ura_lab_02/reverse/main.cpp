#include <string.h>
#include <chrono>
#include <iostream>

// reverse a string
std::string reverse(std::string s) {
  if (s.size() == 1)
    return s;
  else {
    return s.back() + reverse(std::string{s.begin(), s.end() - 1});
  }
}

// reverse a string without using extra memory
template <typename I>
void reverse_inplace(I begin, I end) {
  if (begin >= end) return;
  std::swap(*begin,*(end-1));
  return reverse_inplace(begin+1,end-1);
}

// C string
void reverse_inplace(char* s, int length) {
  if(length <= 0) return;
  std::swap(s[0],s[length-1]);
  return reverse_inplace(s+1,length-2);
}

int main() {
  std::string s = "algoritam";
  {
    auto rev_s = reverse(s);
    std::cout << rev_s << std::endl;
  }
  {
    reverse_inplace(s.begin(), s.end());
    std::cout << s << std::endl;
  }
  {
    char s[] = "algorithm";
    reverse_inplace(s, strlen(s));
    std::cout << s << std::endl;
  }
}
