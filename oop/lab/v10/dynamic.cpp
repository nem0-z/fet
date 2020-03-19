#include <iostream>

struct mojint{

  private:
    int* ptr;

  public:
    mojint(int x):ptr{new int(x)}{}
    mojint(const mojint& a):ptr{new int(getValue())}{}
    int getValue(){
      return *ptr;
    }
    ~mojint(){
      delete ptr;
    }
};  

void ispis(mojint foo){
  std::cout << foo.getValue() << std::endl;
}

int main(void) {
  // int a = 10;
  // int* pa = new int(20);
  // delete pa;
  // int *p = new int[5]; //dinamicki alociraj memoriju za 5 intova
  // korisnickiKreiraniTipPodatka niz[10];  // moze sve dok nas tip ima def constructor
  mojint x{5};
  ispis(x);
  std::cout << x.getValue() << std::endl;
  return 0;
}
