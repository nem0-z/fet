#include <iostream>
#include <thread>
using namespace std;
void foo(int i) {
  while (i-- > 0)
    cout << "Nit: " << std::this_thread::get_id() << " i: " << i << endl;
}
int main(void) {
  thread t1{foo, 5};
  foo(5);
  t1.join();
  return 0;
}
