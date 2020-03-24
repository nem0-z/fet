#include <stdio.h>

const int toBinary(char*,const int);

int main(int argc, char *argv[])
{
  char buffer[50]; 
  const int val = 7;
  const int iterations = toBinary(buffer,val);
  printf("It took me %d iterations to convert %d to binary!\n",iterations,val);
  printf("Number %d in binary equals to: ",val);
  for(int i = 0; i<iterations; ++i)
    printf("%c",buffer[i]);
  printf("\n");
  return 0;
}
