#include <iostream>
class U0 {};
class U1 {};

void baz(int i) {
  if (i == 0)
    throw U0();
  else
    throw U1();
}
void bar(int i) { baz(i); }

void foo() {
  for (int i = 0; i < 2; i++) {
    try {
      bar(i);
    } catch (U0 e) {
      std::cout << "Exception U0 caught\n";
    } catch (U1 e) {
      std::cout << "Exception U1 caught\n";
    }
  }
}

int main() {
  foo();
  std::cout << "Should never get here!\n";
  return 0;
}
