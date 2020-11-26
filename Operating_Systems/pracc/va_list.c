#include <stdio.h>
#include <stdarg.h>

int foo(int n, ...){ int val, i;
  va_list vl;
  va_start(vl,n);
  printf("%p\n\n\n", &vl);
  for(i = 0; i < n; ++i){
    val = va_arg(vl,int);
    printf("%d\n", val);
    printf("%p\n", &val);
  }
  va_end(vl);
  return -1;
}

int bar(int n, ...){
  va_list ap;
  int i, val;
  va_start(ap, n);
  for(i = 0; i < 2; ++i){
    val = va_arg(ap, int);
    printf("%d\n", val);
  }
  va_end(ap);
}

/* int tar(int n, ..., int s){ */
/*   int i, val; */
/*   va_list ap; */
/*   va_start(ap, n); */
/*   for(i = 0; i < n; ++i){ */
/*     val = va_arg(ap, int); */
/*     printf("%d\n", val); */
/*   } */
/*   printf("%d\n", s); */
/*   va_end(ap); */
/*  */
/* } */

int main(void)
{
  /* foo(5, 1, 2, 3, 4, 5); */
  /* int x = 1, y = 3, z = 4; */
  /* printf("Main pointers: %p\n%p\n%p\n", &x, &y, &z);   */
  /* foo(3, x, y, z); */
  /* bar(2,3); */
  /* printf("%d,%d",3); */
  /* tar(3,3,4,5,6); */
  return 0;
}
