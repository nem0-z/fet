#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector<int> v;
  v.push_back(5);
  std::string s = "fadil";
  char x = 'a';
  std::cout << std::hash<std::string>{}(s)%1000 << std::endl;
  std::cout << std::hash<char>{}(x) << std::endl;
  return 0;
}
