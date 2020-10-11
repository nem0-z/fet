#include <stdio.h>
int stepen(int baza, int eksponent)
{
  if(eksponent==0)
    return 1;
  return  baza*stepen(baza, eksponent-1);
}

int main()
{
  int baza = 3;
  int eksponent= 3;
  printf("%d", stepen(baza, eksponent));

  return 0;
}
