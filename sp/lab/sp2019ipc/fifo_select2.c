#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/select.h>

#define BUFFSIZE 4096
#define FIFO_PATH "fifo"

void fail(const char* str) {
    perror(str);
    exit(1);
}

int main() {
    int n, fd;
    fd_set rfds;
    char buf[BUFFSIZE];
    if (mkfifo(FIFO_PATH, 0777) < 0 && errno != EEXIST)
        fail("fifo greska!");
    if ((fd = open(FIFO_PATH, O_RDWR)) < 0)
        fail("greska otvaranje fajla");

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    FD_SET(fd, &rfds);
    while(1)
    {
        if (select(fd+1, &rfds, NULL, NULL, NULL) < 0)
            fail("select greska");
        if (FD_ISSET(0, &rfds))
        {
            printf("Unos na STDIN\n");
            n = read(0, buf, BUFFSIZE);
            write(fd, buf, n);
        }
        else
        {
            printf("Unos u fifo\n");
            n = read(fd, buf, BUFFSIZE);
            write(STDOUT_FILENO, buf, n);
        }
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        FD_SET(fd, &rfds);
    }
    return 0;
}
