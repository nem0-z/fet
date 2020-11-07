#include <stdio.h>

#ifndef SIZE
#define SIZE(x) sizeof(x)/sizeof(int)
#endif /* ifndef SIZE(x) sizeof(x)/sizeof(int) */

int median(int [], int);

/* int median(int arr[], int size){ */
/*   int result, i; */
/*   for(i = 1; i < size; ++i){ */
/*     printf("Comparing %d and %d\n", arr[i-1],arr[i]); */
/*     if (arr[i-1] > arr[i]) */
/*       return -1; */
/*   } */
/*   if (size%2==1) */
/*     result = arr[size/2]; */
/*   else{ */
/*     result = (arr[size/2] + arr[size/2 - 1])/2; */
/*   } */
/*   return result; */
/* } */

int main(void)
{
  int arr[] = {1, 19, 350, 121, 740, 1522};
  int res = median(arr, SIZE(arr));
  printf("Median is: %d\n", res);
  return 0;
}
