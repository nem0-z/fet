#include <iostream>

using namespace std;

// template<typename U = int, class T>
// U foo(T a = 10, U b = 300)
// {
//   cout<<1;
//   return a;
// }
// int foo(int a)
// {
//     cout<<1;
//     return a;
// }

// template<class T,class U=char>
// T foo(T a, T b)
// {
//   cout<<1;
// }
void foo(char a,int b = 5)
{
    cout<<2;
}
void foo(double a, bool b = 10)
{
  cout<<3;
}
void foo(char x, char y = 20)
{
  cout<<4;
}

int main(void)
{
  foo(20,5);
  return 0;
}
