#include <iostream>
#include <thread>
#include "tg.h"
using namespace std;
void foo(int i) {
  while (i-- > 0)
    cout << "Nit: " << std::this_thread::get_id() << " i: " << i << endl;
}
int main(void) {
  TGuard tg{thread{foo, 5}};
  foo(5);
  // tg.get().join();
  return 0;
}
