#include <iostream>

struct Bar {
  char l;
  short s;
  int i;
};

std::ostream& operator<<(std::ostream& o, const Bar& b) {
  o << "{" << b.l << "," << b.s << "," << b.i << "}" << std::endl;
  return o;
}

extern "C" Bar foo(void);
extern "C" void bar(Bar);

int main(void) {
  Bar b = foo();
  std::cout << b << std::endl;
  // std::cout << c << std::endl;
  return 0;
}

