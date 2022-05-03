#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

void foo(int sig) {
    pid_t pid;
    int saved_errno = errno;
    while ((pid = waitpid(-1, 0, WNOHANG)) > 0)
        printf("Unistavam proces: %d\n", pid);
    errno = saved_errno;

}
int main() {
    int i;
    struct sigaction sa;
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
    printf("Roditelj u beskonacoj petlji\n");
    while (1)
        ;
    return 0;
}
