#include <stdio.h>
#include <inttypes.h>

void min_max(void*,const int);

int main(int argc, char *argv[])
{
  int16_t arr[10] = {2,5,8,1,0,4,6,11,5,3};
  min_max(arr,10);
  return 0;
}
