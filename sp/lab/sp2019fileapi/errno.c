#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char* path = "somefile.txt";
    
    int fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0777);
    printf("File descriptor: %d\n", fd);
    if ((fd == -1) && (EEXIST == errno)) {
        //perror("p3 error");
        printf("%s\n", strerror(errno));
        close(STDIN_FILENO);
        fd = open(path, O_WRONLY);
        printf("File descriptor: %d\n", fd);
    }
    return 0;
}

