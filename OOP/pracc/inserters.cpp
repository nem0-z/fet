#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template <class T>
void printArray(const T& array) {
  for (auto x : array) cout << x << " ";
  cout << endl;
}

int main(int argc, char* argv[]) {
  vector<int> vect{1, 5, 13, 65, 2, 4};
  list<int> list{
      3, 6, 7, 3, 1,
  };
  printArray(vect);
  auto x = back_inserter(vect);
  *x = 5;  // works good
  printArray(vect);
  // // auto y = front_inserter(vect);
  // // // *y = 10; //compiles but fails cuz no vector.push_front();
  // auto z = inserter(vect, vect.begin());
  // *z = 10;  // look above, can be redone like this
  auto u = vect.begin();
  *u = 15;
  printArray(vect);
  auto h = inserter(vect, vect.begin() + 3);
  *h = 93;
  printArray(vect);
  vect.erase(vect.begin());
  printArray(vect);
  auto it = vect.erase(vect.begin() + 2, vect.end() - 2);
  printArray(vect);
  *it = 50;
  printArray(vect);
  auto it1 = vect.erase(vect.begin() + 2);
  printArray(vect);
  *it1 = 51;
  printArray(vect);
  // *x = 10;  // should be undefined but works,
  // //           // probably too short stuff so compiler can sort out
  // printArray(vect);
  // printArray(list);
  // auto foo = front_inserter(list);
  // list.push_front(7);
  // *foo = 5;
  // printArray(list);
  return 0;
}
