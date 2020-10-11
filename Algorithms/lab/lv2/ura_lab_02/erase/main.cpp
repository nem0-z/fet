#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter, typename UnaryOpt>
Iter mojRemoveIf(Iter begin, Iter end, UnaryOpt pred) {
  begin = std::find_if(begin, end, pred);
  if (begin == end) return begin;

  for (Iter i = begin + 1; i != end; ++i) {
    if (!pred(*i)) {
      *begin = std::move(*i);
      ++begin;
    }
  }
  return begin;
}

int main() {
  std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto print = [&numbers]() {
    for (auto n : numbers) std::cout << n << ' ';
    std::cout << std::endl;
  };

  print();
  auto it = mojRemoveIf(numbers.begin(), numbers.end(),
                           [](auto el) { return el % 2; });
  // numbers.erase(it, numbers.end());
  print();

  return 0;
}
