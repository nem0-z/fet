#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int>::iterator sorted_position(std::vector<int>& vec,
                                           const int& value) {
  int lo = 0;
  int hi = vec.size() - 1;
  int mid = -1;
  int position = -1;
  if (value <= vec.front())
    return vec.begin();
  else if (value >= vec.back())
    return vec.end();
  while (lo <= hi) {
    mid = (hi + lo) / 2;
    if (value == vec[mid]) {
      position = mid;
      break;
    } else if (value < vec[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
    position = lo;
  }
  return std::vector<int>::iterator(vec.begin() + position);
}

int main(void) {
  std::vector<int> vec{7, 4, 2, 0, -2, -4};
  std::cout << "before sorting" << std::endl;
  for (const auto& x : vec) std::cout << x << " ";
  std::cout << std::endl;
  std::sort(vec.begin(), vec.end());
  std::cout << "before adding: " << std::endl;
  for (const auto& x : vec) std::cout << x << " ";
  std::cout << std::endl;
  std::vector<int>::iterator it = sorted_position(vec, -5);
  vec.insert(it, -5);
  // std::vector<int>::iterator it1 = sorted_position(vec, 54);
  // vec.insert(it1, 54);
  // std::vector<int>::iterator it2 = sorted_position(vec, -5);
  // vec.insert(it2, -5);
  // std::vector<int>::iterator it3 = sorted_position(vec, 300);
  // vec.insert(it3, 300);
  // std::vector<int>::iterator it4 = sorted_position(vec, -12);
  // vec.insert(it4, -12);
  // std::vector<int>::iterator it5 = sorted_position(vec, 14);
  // vec.insert(it5, 14);
  // std::cout << "after adding: " << std::endl;
  for (const auto& x : vec) std::cout << x << " ";
  std::cout << std::endl;
  return 0;
}
