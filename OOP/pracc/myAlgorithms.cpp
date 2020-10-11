#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
// Find element in range
// Returns an iterator to the first element in the range [first,last) for
// which pred returns true. If no such element is found, the function returns
// last.
template <typename T>
typename std::vector<T>::iterator moj_find(typename std::vector<T>::iterator begin,
                                typename std::vector<T>::iterator end, T test) {
  while (begin != end) {
    if (*begin++ == test) return begin; 
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> x{5, 8, -3, 7, 250, -97, 12, 745, -123};
  std::vector<double> y{5.8, 8.21, -3, 7, 250, -97.24, 12.11, 745, -123};
  int test;
  std::cin >> test;
  auto it =
      moj_find(x.begin(), x.end(), test);
  *it = 40; //overwrite
  for (auto& el:x) std::cout<<el<<" ";
  std::cout<<std::endl;
  double test1;
  std::cin>>test1;
  auto it1 = moj_find(y.begin(), y.end(), test1);
  auto insert = inserter(y,it1);
  *insert = 80; //add and change size obv
  for (auto& el:y) std::cout<<el<<" ";

  return 0;
}
