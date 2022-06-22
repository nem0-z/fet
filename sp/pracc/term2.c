#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf[30] = {0};
  while (1) {
    int n = read(STDIN_FILENO, &buf, sizeof(buf));
    if (n < 0)
      printf("error");
    else
      printf("%s", buf);
  }
  return 0;
}
