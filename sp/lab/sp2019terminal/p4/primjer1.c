#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (isatty(0))
        printf("%s\n", ttyname(0));
    else
        printf("nije terminal!\n");
    return 0;
}
