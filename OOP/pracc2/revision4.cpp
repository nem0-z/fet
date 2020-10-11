#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct A {
  int a;
  A() { cout << "Constructing..." << endl; }
  A(int x) : a{x} {}
  ~A() { std::cout << "Destructing..." << a << std::endl; }
};

std::ostream& operator<<(std::ostream& stream, const A& x) {
  stream << x.a << endl;
  return stream;
}

int main(void) {
  // const int a[] = {1,2,3,4,5};
  A y{5};
  const A& magic = A{4};
  A z{6};
  // A arr[2] = {y,z};
  // for (int i = 0; i < sizeof(arr) / sizeof(A); ++i) cout << arr[i];
  // A* niz = new A[5]{y, z, z, z};
  // for (A* p{niz}; p < niz + 5; p++) cout << *p;
  // delete[] niz;
  return 0;
}
