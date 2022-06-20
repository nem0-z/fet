#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[]) {
    int fd = open("konjko.file", O_WRONLY | O_TRUNC, 0777);
    if (fd == -1) {
        // printf("%s", strerror(errno));
        perror("Custom poruku");
        return 0;
    }
    const char *tekst = "ja upisujem ovde nesto balkdlsajdlksajdlkadjsalkdjsad";
    const char *teksting = "IJEEEEEEEEEEj";
    if (fork() == 0) {
        //kid
        write(fd, tekst, strlen(tekst));
        write(STDERR_FILENO, "konj", 4);
    } else {
        write(fd, teksting, strlen(teksting));
        write(STDERR_FILENO, "ajla", 4);
    }
    return 0;
}
