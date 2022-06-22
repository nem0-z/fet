#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    if (isatty(0)) {
        printf("%s\n", ttyname(0));
    } else {
        printf("nije terminal ovaj hepek: %s\n", ttyname(0));
    }
    return 0;
}
