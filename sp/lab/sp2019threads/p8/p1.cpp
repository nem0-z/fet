#include <thread>
#include <iostream>
using namespace std;
void foo() {
  cout << "Pozdrav od niti: " <<
    std::this_thread::get_id() << endl;
}
int main(void) {
  thread t1{foo};
  t1.join();
  foo();
  return 0;
}
