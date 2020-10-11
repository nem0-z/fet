#include <iostream>
#include <vector>
#include <list>
using namespace std;

class A{
  private:
    int broj = 0;
  public:
  A(){
    cout<<1<<endl;
  }
  A(const A&){
    cout<<2<<endl;
  }
  ~A(){
    cout<<3<<broj<<endl;
  }
  A (int x){
    broj = x;
  }
};

// namespace moj{
//   A a;
// }

// A x;

int main(void)
{
  // A a;
  // A b(a);
  // static A y(5);
  list<int> vec{5,2,1,7,5,7,2,6,6,5,1,2,2,2,2,2};
  cout<<*(vec.end())<<endl;
  return 0;
}
