#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char * argv[]){

  int status;
  pid_t cpid, pid;
  int i=0;
  int newFD;

  int fd = open("newfile.txt", O_WRONLY | O_CREAT, 0777);
  printf("FD %d\n", fd);

  if (fd < 0) {
    perror("open failed");
    _exit(1);
  }

  if(dup2(fd,1) < 0) {
    perror("dup2 failed");
    _exit(1);
  }
  
  while(1){ //loop and fork children

    cpid = fork();

    if( cpid == 0 ){
      /* CHILD */

      pid = getpid();

      printf("Child: %d: i:%d\n", pid, i);

      //set i in child to something differnt
      i *= 3;
      printf("Child: %d: i:%d\n", pid, i);
      
      int response = write(4, "test", 4);
   //   printf("response %d\n", response);
            printf("err %d\n", errno);
 //printf("test\n");
     
_exit(0); //NO FORK BOMB!!!
    }else if ( cpid > 0){
      /* PARENT */

      //wait for child
      wait(&status);

      //print i after waiting
      printf("Parent: i:%d\n", i);

      newFD = open("newfile2.txt", O_WRONLY | O_CREAT, 0777);
      printf("NEW FD %d\n", newFD);
      i++;
      if (i > 5){       
        break; //break loop after 5 iterations
      }

    }else{
      /* ERROR */
      perror("fork");
      return 1;
    }

    //pretty print
    printf("--------------------\n");
  }

  return 0;
}
