#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int divide(int a, int b) {
  if (!b) return -1;
  if (a < b) return 0;
  return 1 + divide(a - b, b);
}

int mult(int a, int b) {
  if (!b) return 0;
  return a + mult(a, b - 1);
}

bool palindrome(const char* s, int n) {
  // std::cout << "Comparing letters: " << *s << " and " << s[n-1] << std::endl;
  if (n == 1 || n == 0) return true;
  if (*s != s[n - 1]) return false;
  return palindrome(s + 1, n - 2);
}

int sum(const int* array, int n) {
  if (!n) return 0;
  return *array + sum(array + 1, --n);
}

int pp(int n) {
  if (n < 2) return 1;
  if (n & 1) --n;
  return n * pp(n - 2);
}

bool push_unique(std::vector<int>& vec, int toAdd) {
  for (auto a : vec)
    if (a == toAdd) return false;
  vec.emplace_back(toAdd);
  return true;
}

std::vector<int>::iterator sorted_position(std::vector<int>& vec,
                                           const int& add) {
  int lo = 0;
  int hi = vec.size() - 1;
  int position = -1;
  if (add <= vec.front())
    return vec.begin();
  else if (add >= vec.back())
    return vec.end();
  while (lo <= hi) {
    int mid = (hi + lo) / 2;
    std::cout << "Lo:" << lo << " Mid:" << mid << " Hi:" << hi << std::endl;
    const int midElem = vec[mid];
    std::cout << "Middle element:" << midElem << std::endl;
    std::this_thread::sleep_for(1s);
    if (add == midElem) {
      return vec.begin() + mid;
    }
    if (add < midElem)
      hi = mid - 1;
    else
      lo = mid + 1;
    position = lo;
  }
  return vec.begin() + position;
}

template <typename Iter, typename P>
Iter mypartition(Iter begin, Iter end, const P& p) {
  auto t = begin;
  auto r = end;
  while (true) {
    while ((begin != end) && p(*begin)) ++begin;
    auto tmpBegin = begin;
    while ((tmpBegin != end) && !p(*tmpBegin)) ++tmpBegin;
    if (tmpBegin == end) return begin;
    std::swap(*begin++, *tmpBegin);
  }
}

void parni(int n){
  if(n&1) --n;
  if(n>2)
    parni(n-2);
  cout << n << " ";
}

int main(int argc, char* argv[]) {
  parni(9);
  // std::cout << divide(24, 5) << std::endl;
  // std::cout << mult(24, 5) << std::endl;
  // const char* s = "sike";
  // std::cout << palindrome(s, strlen(s)) << std::endl;
  // const int niz[] = {5, 1, 2, 3, 7, 140};
  // std::cout << sum(niz, sizeof(niz) / sizeof(int)) << std::endl;
  // std::cout << pp(7) << std::endl;
  // vector<int> v{7, 2, 4, 6, 1, 2, 3};
  // std::cout << std::boolalpha << push_unique(v, 2) << std::endl;
  // std::sort(v.begin(), v.end());
  // for (auto a : v) cout << a << " ";
  // cout << endl;
  // const int toAdd = 5;
  // auto it = sorted_position(v, toAdd);
  // v.insert(it, toAdd);
  // for (auto a : v) cout << a << " ";
  // cout << endl;
  // std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // std::partition(v.begin(), v.end(), [](int elem) { return elem & 2 == 0; });
  // sadržaj vektora v nakon poziva:
  // v = {0, 8, 2, 6, 4, *5*, 3, 7, 1, 9};
  // funkcija bi vratila iterator koji pokazuje na element 5 (boldiran).
  // std::vector<int> v{2, 1, 3, 8, 4, 5, 6, 9, 7};
  // auto s = mypartition(v.begin(), v.end(),
  //                      [](const int& e) -> bool { return e < 4; });
  // for (auto it = begin(v); it < s; ++it) std::cout << *it << ' ';
  // std::cout << '*';
  // for (; s < end(v); ++s) std::cout << ' ' << *s;
  // std::cout << std::endl;
  // Ispis programa bi bio
  // 2 1 3 * 8 4 5 6 9 7
  return 0;
}
