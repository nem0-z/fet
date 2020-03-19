#include<iostream>
using namespace std;

struct A{
  A() {cout<<"A()"<<endl;}
  A(const A&) {cout<<"A(A&)"<<endl; }
};

struct B{
  B() {cout<<"B()"<<endl;}
  B(const B&) {cout<<"B(B&)"<<endl;}
};

struct C{
  A a;
  B b;
  char c;
  C() = default;
  C(char l) : c{l} {cout<<"C("<<c<<")"<<endl;}
  C(const C& x) : a{x.a}, b{x.b} {cout<<"Sinisa"<<endl;}
  ~C() {cout<<"~C("<<c<<")"<<endl;}
};



  // C a('a');
int main(){
  static C a{};
  // cout<<"---1"<<endl;
  // C b('b');
  // cout<<"----2"<<endl;
  // C c(a);
  // cout<<"----3"<<endl;
  return 0;
}

namespace boris{
 extern C a;
}

