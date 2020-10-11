#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class Iter, class UnaryOpt>
void mojDesno(Iter start, Iter end, UnaryOpt broj) {
  if(start==end) throw std::out_of_range("Fail");
  auto kraj = --end;
  for (Iter poc = start, it; poc != kraj; --kraj) {
    it = std::find_if(poc, kraj, broj);
    std::swap(*it, *kraj);
  }
}
template <class Iter, class UnaryOpt>
void mojLijevo(Iter start, Iter end, UnaryOpt broj) {
  auto kraj = --end;
  for (Iter it; start != kraj; ++start) {
    it = std::find_if(start, end, broj);
    std::swap(*it, *start);
  }
}
static int ajla;
int main(void) {
  std::list<int> v{};
  mojDesno(v.begin(), v.end(), [](int a) { return a <= 2; });
  for (const auto& x : v) cout << x << " ";
  cout << endl;
  std::vector<char> v1{2,5,'c'};
  // mojLijevo(v.begin(), v.end(), [](int a) { return a <= 2; });
  // for (const auto& x : v) cout << x << " ";
  // cout << endl;
  return 0;
}
