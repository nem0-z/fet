#include <iostream>

struct A{
  A(){
  std::cout << 1 << std::endl;}
  A (int a){
    std::cout << "int" << std::endl;
  }
  A(const A&){
    std::cout << 2 << std::endl;
  }
  A(A&&){
    std::cout << 3 << std::endl;
  }
  A operator=(const A&){
    std::cout << 4 << std::endl;
  }
  A operator=(const A&&){
    std::cout << 5 << std::endl;
  }
  ~A(){
    std::cout << 6 << std::endl;
  }
};

struct B:A{
  
};

void f1(const A& a){
  std::cout << "f1" << std::endl;
}
int main(void)
{
  B x;
  f1(x);
  // A* ptr;
  // ptr = &x;
  // *ptr = A{5};
  // delete ptr;
  return 0;
}
