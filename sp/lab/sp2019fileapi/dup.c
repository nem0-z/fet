#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{ 
    int file_desc = open("dup.txt", O_WRONLY | O_APPEND | O_CREAT, 0777); 
      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
//    close(0);      
    int copy_desc = dup(file_desc); 
  
    write(copy_desc,"This will be output to the file named dup.txt\n", 46); 
          
    write(file_desc,"This will also be output to the file named dup.txt\n", 51); 
    
    printf("file_desc %d\n", file_desc);
    printf("copy_desc %d\n", copy_desc);
    dup2(file_desc, 1);
    
    printf("This will be printed in the file dup.txt too\n");      
    
    return 0; 
} 
