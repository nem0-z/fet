#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    signal(SIGKILL, SIG_DFL);
}

int main()
{
    signal(SIGKILL, ouch);
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
