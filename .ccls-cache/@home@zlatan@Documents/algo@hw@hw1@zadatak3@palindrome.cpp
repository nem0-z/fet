#include <cstring>
#include <iostream>

bool palindrome(const char* s, int n) {
  if (n < 0) return false;
  if (n == 1 || n == 0) return true;
  if (*s != s[n - 1]) return false;
  return palindrome(s + 1, n - 2);
}

int main(void) {
  const char* str1 = "anavolimilovana";
  const char* str2 = "rotoaor";
  const char* str3 = "rotor";
  std::cout << std::boolalpha << palindrome(str1, strlen(str1)) << std::endl;
  std::cout << std::boolalpha << palindrome(str2, strlen(str2)) << std::endl;
  std::cout << std::boolalpha << palindrome(str3, strlen(str3)) << std::endl;
  return 0;
}

