#include <iostream>
using namespace std;

struct Foo{
  int a;
  Foo() = default;
  Foo(int x){}
};


int main(void)
{
  // Foo bar{2};
  // int a[10];
  // int* p = a;
  // std::cout << p << std::endl;
  // int* hp = new int [10];
  // std::cout << hp << std::endl;
  // // delete [] hp ;
  // Foo* hfoo = new Foo[10];
  // std::cout << hfoo << std::endl;
  auto hptr = (Foo*) malloc(10);
  std::cout << hptr << std::endl;
  free(hptr);
  return 0;
}
