#include <bits/stdc++.h>

namespace ura {
template <typename It, typename P>
It stable_partition(It begin, It end, P p) {
  auto n = end - begin;
  if (n == 0) return begin;
  if (n == 1) {
    if (p(*begin))
      return end;
    else
      return begin;
  }

  auto middle = begin + n / 2;
  auto p1 = ura::stable_partition(begin, middle, p);
  auto p2 = ura::stable_partition(middle, end, p);

  return std::rotate(p1, middle, p2);
}
}  // namespace ura

int main(void) {
  std::vector<int> v;
  for (int i = 0; i < 20; ++i) v.push_back(i);
  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;
  ura::stable_partition(v.begin(), v.end(), [](int a) { return a % 2 == 0; });
  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;
  return 0;
}
