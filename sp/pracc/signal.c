#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void parent_handler(int sig) { printf("Parent processing signal: %d\n", sig); }

void kid_handler(int sig) {
  sleep(1);
  printf("Kid processing signal: %d\n", sig);
}

void foo(int sig) {
  pid_t pid;
  int saved_errno = errno;
  while ((pid = waitpid(-1, 0, WNOHANG)) > 0)
    printf("Unistavam proces: %d\n", pid);
  errno = saved_errno;
}

int main() {
  int i;
  pid_t pid;
  struct sigaction sa;

  pid = fork();
  if (pid == 0) {
    signal(SIGINT, kid_handler);
  } else {
    signal(SIGINT, parent_handler);
    sa.sa_handler = foo;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    sigaction(SIGCHLD, &sa, 0);
    for (i = 0; i < 5; i++) {
      if (fork() == 0) {
        printf("Pozdrav od: %d\n", (int)getpid());
        sleep(1);
        exit(0);
      }
    }
  }

  while (1)
    ;
  return 0;
}
