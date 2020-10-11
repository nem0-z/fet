#include <iostream>

struct C {
  int x;
  C() { std::cout << "def" << std::endl; }
  explicit C(int i) : x{i} { std::cout << "i " << x << std::endl; }
  C(double) { std::cout << "d" << std::endl; }
  ~C() { std::cout << "dest  " << x << std::endl; }
  C(const C &) { std::cout << "copy" << std::endl; }
};
namespace sinisa{
    // C z(8);
}
// C x(7);
// C a(10);
//
// namespace adna{
//   C k;
// }

// const int ajla; //bozije davanje
// extern const int foo;
// const int foo = 5;
int main(int argc, char *argv[]) {
  // C adna(15);
  // static C y(6);
  // bool sinisa;
  C{ C{} };  // boze sacuvaj
  // C{C{}}; //boze sacuvaj opet nista to ovo je kao ok
  // C x(C{});
  return 0;
}

//foo(int) i foo(double) pozovi sa foo('a')
//kod liste kako provjeriti jel iteratorBegin prije iteratorEnd(vektor podrzava < >)
//globalne varijable na sta se inicijaliziraju (bool x globalni bio na false)
//int x{}; jel isto sto i int x;



