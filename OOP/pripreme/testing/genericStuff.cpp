#include <algorithm>
#include <iostream>
#include <vector>

#include <list>

template <typename OutputIt, typename Value>
OutputIt mojFind(OutputIt start, OutputIt end, Value val) {
  while (start != end)
    if (*start++ == val) return --start;
  return end;
}

template <typename InputIt, typename UnaryOpt>
InputIt mojFindIf(InputIt start, InputIt end, UnaryOpt predicate) {
  while (start != end)
    if (predicate(*start++)) return --start;
  return end;
}

template <typename T>
void swapIt(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

int main(void) {
  std::list<int> v{9, 1, 5, 6, 3, 1, 15};
  auto x = mojFind(v.begin(), v.end(), 5);
  *x = 10;
  for (const auto& x : v) std::cout << x << " ";
  std::cout << '\n';
  auto y = mojFindIf(v.begin(), v.end(), [](int x) { return x == 6; });
  *y = 30;
  for (const auto& x : v) std::cout << x << " ";
  std::cout << '\n';
  int foo1 = 30;
  int foo2 = 10;
  std::cout << foo1 << " " << foo2 << std::endl;
  swapIt(foo1,foo2);
  std::cout << foo1 << " " << foo2 << std::endl;

  return 0;
}
