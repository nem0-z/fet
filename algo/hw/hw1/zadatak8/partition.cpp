#include <algorithm>
#include <iostream>
#include <vector>

namespace zadatak8 {
template<typename T>
void swap(T first, T second){
  T tmp = second;
  first = second;
  second = tmp;
}

template <typename ForwardIter, typename P>
ForwardIter partition(ForwardIter begin, ForwardIter end, const P& p) {
  auto last = --end;
  while (true) {
    while (p(*begin)) {
      if (begin == end) return end;
      ++begin;
    }
    auto tmpBegin = begin;
    while (!p(*tmpBegin)) {
      if (*tmpBegin == *last) return begin;
      ++tmpBegin;
    }
    swap(*begin++, *tmpBegin);
  }
}
}  // namespace zadatak8

int main(void) {
  std::vector<int> v{2, 1, 3, 8, 4, 5, 6, 9, 7};
  auto s = partition(v.begin(), v.end(),
  [](const int& e) { return e < 4; });
  for (auto it = v.begin(); it < s; ++it) std::cout << *it << " ";
  std::cout << '*';
  for (; s < v.end(); ++s) std::cout << " " << *s;
  std::cout << std::endl;
  // std::vector<int> v{-3,-5,8,1,34,-9,1,-1};
  //  auto s = zadatak8::partition(v.begin(), v.end(),
  //                              [](const int& e) { return e == -9; });
  //  *s = 15;
  //  for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
  return 0;
}
