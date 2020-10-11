#include "vjezbamC2.h"
int main(int argc, char* argv[]) {
  long long int arrSize = 3;
  int* p;
  p = (int*)malloc(arrSize * sizeof(int));
  assert(p != NULL && "Not enough space!");
  /* scanArr(p, arrSize); */
  printArr(p, arrSize);
  arrSize *= 200;
  /* scanArr(p, arrSize); */
  /* printArr(p, arrSize); //check what happens */
  p = (int*)realloc(p, arrSize);
  /* scanArr(p, arrSize); */
  printArr(p, arrSize);  // check what happens
  return 0;
}
