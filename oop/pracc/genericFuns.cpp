#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U>
auto saberi(T a, U b) {
  return a + b;
}

template <class X>
auto saberi(const vector<X>& container) {
  X suma{};
  for (auto& item : container) suma += item;
  cout << "Genericka funkcija ";
  return suma;
}

auto saberi(const vector<double>& container) {
  auto suma = 0;
  for (auto& item : container) suma += item;
  cout << "Konkretna funkcija ";
  return suma;
}

int main(void) {
  vector<int> vec{1, 7, 2, 6, 8};
  vector<double> vecDouble{3.6, 22.4, 6.3, 8.31, 7.2};
  list<int> lista{6, 38, 2, 8, 32};
  int x = 5;
  double y = 10.45;
  bool x1 = true;
  string y1 = "zlatan";
  string y2 = "sinisa";
  cout << saberi<int>(y, x) << endl;
  cout << saberi<int>(y, x1) << endl;
  cout << saberi(y1, y2) << endl;
  cout << saberi('a', 5) << endl;
  cout << saberi(vec) << endl;
  cout << saberi(vecDouble) << endl;
  return 0;
}
