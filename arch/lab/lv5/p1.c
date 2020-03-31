#include<stdio.h>

void power(int*,int);

int main(void)
{
  int stepen = 6;
  int num = 2;
  power(&num,stepen);
  printf("%d",num);
  return 0;
}


