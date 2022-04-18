#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
  int fd;
  fd = open("lseek.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP);
  if( fd < 0 ) {
    perror("open error");
    exit(1);
  }
  
  if( write(fd, buf1, 10) != 10 ) {
    perror("buf1 write error");
    exit(1); 
  }
  /* offset now = 10 */
  
  if( lseek(fd, 40, SEEK_SET) == -1 ) {
    perror("lseek error");
    exit(1);
  }
  /* offset now = 40 */
  
  if(write(fd, buf2, 10) != 10){
    perror("buf2 write error");
    exit(1);
  }
  /* offset now = 50 */
  
  exit(0);
}
