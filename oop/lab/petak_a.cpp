#include <functional>
#include <iostream>
#include <vector>

template <class InputIt, class UnaryOpt, class ContType>
void takeWhile(InputIt start, InputIt end, UnaryOpt lambda, ContType& cont) {
  if (end < start) throw std::invalid_argument("SinisHa");
  while (start != end) {
    if (lambda(*start))
      cont.push_back(*start);
    else
      break;
    ++start;
  }
}

template <class ContType>
void outputVec(const ContType& cont) {
  for (auto& x : cont) std::cout << x << " " << std::endl;
}

int main(void) {
  std::vector<int> v{2, 3, 4, 5, 0, 1};
  std::vector<int> k{};
  try {
    takeWhile(v.begin(), v.end(), [](int i) { return i < 4; }, k);
    outputVec(k);
  } catch (std::invalid_argument a) {
    std::cout << a.what() << std::endl;
  }
  return 0;
}
