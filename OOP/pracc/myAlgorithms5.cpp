#include <iostream>
#include <vector>

using namespace std;
template <class T>
void mySwap(T& x, T& y) {
  T z = y;
  y = x;
  x = z;
}

void output(std::vector<int>::const_iterator start,std::vector<int>::const_iterator end)
{
  while(start!=end)
  {
    cout<<*start++<<" ";
  }
  cout<<endl;
}
int main(int argc, char* argv[]) {
  vector<int> vect{5, 10, 6, 7, 2, 9};
  vector<int> test{8, 23, 7, 2, 7, 1};
  auto start1 = vect.begin();
  auto end1 = vect.end();
  auto start2 = test.begin();
  auto end2 = test.end();
  // int a1 = 5;
  // int a2 = 10;
  // cout << a1 << endl;
  // cout << a2 << endl;
  // mySwap(a1, a2);
  // cout << a1 << endl;
  // cout << a2 << endl;
  output(start1,end1);
  output(start2,end2);
  mySwap(vect,test);
  output(start1,end1);
  output(start2,end2);
  return 0;
}
