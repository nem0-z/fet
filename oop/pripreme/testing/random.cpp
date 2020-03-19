#include <iostream>
using namespace std;


struct A{
  int a;
  explicit A(int a) {}
  A(const A& x): a{x.a} {}
  ~A(){}
};

struct B{
  A a;
  B() = default;
};


#include <vector>
int main(void)
{
  A x( 5.5 );
  // int a = 10;
  // const int& b = a;
  //  int c = 6;
  //  int& d = c;
  //  c = 9;
  //  a = 8;
  //  d = 8;
  // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
  // const int& x = 2;
  // std::vector<int> v;
  // int unos;
  // while(true)
  // {
  //   std::cin>>unos;
  //   if(!bool(std::cin)) break;
  //   v.push_back(unos);
  // }
  // for(auto x:v) cout<<x<<" ";
  // cout<<endl;
  return 0;
}
