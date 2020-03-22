#include <stdio.h>

int main(int argc, char* argv[]) {
  char res[40];
  const char* s = "abCdEfgzh ?";
  int i = 0;
  while (*s != '\0') {
    if (*s > 96 && *s < 123) {
      res[i] = *s - 32;
    } else
      res[i] = *s;
    ++s;
    ++i;
  }
  printf("%s", res);
  return 0;
}
