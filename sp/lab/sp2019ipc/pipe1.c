#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void fail(const char* str) {
    perror(str);
    exit(1);
}

int main() {
    int n, fd[2];
    pid_t pid;
    char linija[MAX];
    // pipa
    if (pipe(fd) < 0)
        fail("pipe greska");

    printf("Read: %d, Write: %d\n", fd[0], fd[1]);
            dup2(fd[1], STDOUT_FILENO);
    if ((pid = fork()) < 0)
        fail("fork greska");
    else
        if (pid > 0) {
            close(fd[0]);
            
            printf("pox");
            // write(fd[1], "Pozdrav svima!\n", 15);
        }
        else {
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            n = read(0, linija, MAX);
            // scanf("%s", linija);
            // write(STDOUT_FILENO, linija, n);
            printf("Process ID: %d\n", getpid());
        }
    return 0;
}
