#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using lista_it = std::list<int>::iterator;

template<typename T>
void output(T a)
{
  cout<<a<<endl;
}

void output(lista_it a, lista_it b) {
  // for (auto it = a; it!= b; ++it)
  // {
  //   cout<<*it<<" ";
  // }              ovo je manje fensi
  while (a != b) cout << *a++ << " ";  // ovo je vise fensi
  cout << endl;
}
lista_it find1(lista_it a, lista_it b, function<bool(int)> test) {
  while (a != b) {
    if (test(*a))
      return a;
    else
      ++a;
  }
  return b;
}

int main(void) {
  list<int> a{1, 2, 3, 5, 7, 8, 12, 54, 123, 64, 1, 72, 5};
  // auto it1 = ++a.begin();
  // auto it2 = a.end();
  // output(it1,it2);
  // int unos;
  // cin >> unos;
  // auto it = find1(a.begin(), a.end(), [unos](int x) { return x == unos; }); //vazno
  // *it = 10;
  // output(a.begin(), a.end());
  output(20);
  output(20.512);
  output("sinisha");
  output('a');
  return 0;
}
