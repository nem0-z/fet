#include <stdarg.h>
#include <stdio.h>

int main(void) {
  unsigned int i = 0x00646c72;
  printf("H%x Wo%s", 57616, &i);
  /* printf("%s\n",&i); */
  /* printf("%d\n",&i); */
  /* printf("%x\n",57616); */
  int a = 0x12345678;
  int s = 0x78;
  unsigned char *c = (unsigned char *)(&a);
  if (*c == 0x78) {
    printf("little-endian\n");
    /* printf("%s\n%s\n", &a, &s); */
  } else {
    printf("big-endian\n");
  }
  return 0;
}
