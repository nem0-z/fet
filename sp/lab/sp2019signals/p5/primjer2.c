#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void moj_handler(int sig) {
    printf("Procesiram signal br %d\n",sig);
    alarm(3);

}
int main(int argc, char *argv[]) {
    signal(SIGALRM, moj_handler);
    alarm(5);
    while(1)
        ;
    return 0;
}
