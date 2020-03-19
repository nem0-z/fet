#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  int a = 10;
  int b = 5;
  const int* ptr = &a;
  // *ptr = 4;  // nope
  ptr = &b;  //np
  int* const ptr1 = &b;
  *ptr1 = 5; //np
  // ptr1 = &a; //nope
  const int x = 20;
  const const int* constPtr = &x;
  constPtr = &a;
  const int* const constPtr2 = &x;
  return 0;
}
