#include <algorithm>
#include <iostream>
#include <vector>

namespace zadatak8 {
template <typename ForwardIter, typename P>
ForwardIter partition(ForwardIter begin, ForwardIter end, const P& p) {
  while (true) {
    while (p(*begin)) ++begin;
    if (begin == end) return end;
    auto tmpBegin = begin;
    while ((tmpBegin != end) && !p(*tmpBegin)) ++tmpBegin;
    if (tmpBegin == end) return begin;
    std::swap(*begin++, *tmpBegin);
  }
}
}  // namespace zadatak8

int main(void) {
  // std::vector<int> v{2, 1, 3, 8, 4, 5, 6, 9, 7};
  // auto s = partition(v.begin(), v.end(), [](const int& e) { return e < 4; });
  // for (auto it = v.begin(); it < s; ++it) std::cout << *it << " ";
  // std::cout << '*';
  // for (; s < v.end(); ++s) std::cout << " " << *s;
  // std::cout << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  auto s = zadatak8::partition(v.begin(), v.end(),
                               [](const int& e) { return e % 2; });
  v.insert(s,15);
  for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
  return 0;
}
