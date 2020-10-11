#include <iostream>
#include <vector>
using namespace std;



struct B{
    B(){cout<<"ok"<<endl;}
    B(int){cout<<"def"<<endl;}
    ~B(){cout<<"del"<<endl;}
};

struct A{
  int b;
  B x;
  A(): b{5},x{B{5}}{cout<<"boris"<<endl;}
  ~A(){cout<<"sinisa"<<endl;}

};
// namespace meks{
// template<typename T = int>
// auto foo(T a = 5)
// {
//   cout<<a;
//   return a;
// }
// B a(5);
// }

int main(void)
{
  A x;
  // meks::foo(); 
  return 0;
}
