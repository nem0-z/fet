#include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 32 

int main(int argc, char *argv[])
{
    char buf[BUFFSIZE];
    unsigned int n = 0; 

    ssize_t nb= 0;
    while((nb = read(0, buf + n, BUFFSIZE - n)) > 0)
    {
        printf("Read nbytes: %ld\n", nb);
        n += nb;
    }

    printf("EOF deteced. Read nbytes: %u", n);
    printf("Buffer contains %s", buf);
    return 0;
}
