#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& vec, int value) {
  for (const auto& item : vec) {
    if(item == value) return false;
  }
  vec.push_back(value);
  return true;
}

int main(void) {
  std::vector<int> vec = {1, 5, 4, 3};
  for (const auto& item : vec) std::cout << item << " ";
  std::cout << '\n';
  std::cout << std::boolalpha << push_unique(vec, 4) << std::endl;
  for (const auto& item : vec) std::cout << item << " ";
  std::cout << '\n';
  std::cout << std::boolalpha << push_unique(vec, 2) << std::endl;
  for (const auto& item : vec) std::cout << item << " ";
  std::cout << '\n';
  return 0;
}
