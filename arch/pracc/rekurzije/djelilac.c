#include <stdio.h>


/* int stepen(int baza, int eksponent) */
/* { */
/*   if(eksponent==0) */
/*     return 1; */
/*   return (baza*stepen(baza,eksponent-1)); */
/* } */

/* int hfc(int n1, int n2) */
/* { */
  /* if(n2!=0) */
    /* return n1; */
  /* return hfc(n2,n1%n2); */
/* } */

int stepen(int,int);
int hfc(int,int);

int main ()
{
  int baza;
  int eksponent;
  scanf("%d%d",&baza,&eksponent);
  printf("%d\n",stepen(baza,eksponent));
  return 0;
}
