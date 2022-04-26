#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

void fail(const char *str) {
  perror(str);
  exit(1);
}

int main() {
  int n, fd[2];
  pid_t pid;
  char buf[MAX];

  if (pipe(fd) < 0)
    fail("pipe greska");

  if ((pid = fork()) < 0)
    fail("fork greska");

  if (pid > 0) {
    close(fd[0]);
    char inbuf[MAX];
    for (int i = 0; i < MAX; i++)
        inbuf[i] = 'x';

    if ((read(STDIN_FILENO, inbuf, MAX)) <= 0)
        fail("read error");

    const int w = write(fd[1], inbuf, MAX);
    printf("I have written %d bytes to pipe.\n", w);
  } else {
    close(fd[1]);
    n = read(fd[0], buf, MAX);
    printf("I have read %d bytes from pipe.\n", n);
    write(STDOUT_FILENO, buf, n);
  }
  return 0;
}
