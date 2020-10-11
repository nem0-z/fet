#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const char* str = "This is a sentence.";
  for (int i = 0; str[i] != '\0'; ++i) {
    printf("%c", str[i]);
  }
  /* int k; */
  /* while(scanf("%d",&k)){ */
  /*   printf("Ljubi te brat!!\n"); */
  /* } */
  return 0;
}
