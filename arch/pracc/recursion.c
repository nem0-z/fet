#include <stdio.h>
#include <string.h>

/* int isPalindrome(char*s, int len){ */
/*   if(len<2) */
/*     return 1; */
/*   else */
/*     return s[0] == s[len-1] && isPalindrome(s+1, len-2); */
/* } */

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* static void partition_impl(int* first, int* second, int (*predicate)(int)) { */
/*   if (first == second) return; */
/*   if (predicate(*first)) { */
/*     swap(first, second); */
/*     --second; */
/*   } else { */
/*     ++first; */
/*   } */
/*   partition_impl(first, second, predicate); */
/* } */
/*  */
/* void partition(int* niz, int size, int (*predicate)(int)) { */
/*   partition_impl(niz, niz + size - 1, predicate); */
/* } */
/*  */
/* static void partition_impl(int* first, int* second, int (*predicate)(int)); */
void partition(int* niz, int size, int (*predicate)(int));
int isPalindrome(char*, int);

int arr[7] = {-4, 5, -14, 2, 5, -7, 3};

int negative(int num) { return num < 0; }

int main(void) {
  /* char niz[50] = "rotori"; */
  /* if (isPalindrome(niz, strlen(niz))) { */
  /*   printf("Palindrom\n"); */
  /* } else { */
  /*   printf("Nije palindrom\n"); */
  /* } */
  partition(arr, 7, negative);
  int i = 0;
  while (i < 7) {
    printf("%d ", arr[i++]);
  }
  return 0;
}
