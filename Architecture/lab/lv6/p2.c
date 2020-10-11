#include <stdio.h>
/* Funkcija partition koja prima 3 parametra */
/* 1.pointer na pocetak niza */
/* 2.broj elemenata niza */
/* 3.pointer na predicate funkciju */
/*  */
/* Svi elementi koji zadovoljavaju predicate su na desnoj strani niza */
/* a ostali na lijevoj strani */

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

static void partition_impl(int*, int*, int(*predicate)(int));



void partition(int * niz, int size, int (*predicate)(int));

int arr[7] = {4, 5, -9, 2, 5, -7, -3};

int negative (int num){
  return num<0;
}

int main(void)
{
  partition(arr,7,negative);
  int i = 0;
  while (i<7) {
    printf("%d ",arr[i++]);
  }
  printf("\n");
  return 0;
}
