#include <stdio.h>
#include <signal.h>
void moj_handler(int sig) {
    printf("Procesiram signal br %d\n",sig);
}

int main(int argc, char *argv[]) {
    signal(SIGTSTP, SIG_IGN);
    signal(SIGINT, &moj_handler);
    while(1)
        ;
    return 0;
}

