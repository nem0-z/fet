#include <stdio.h>
int duzina(char* s)
{
  if(*s=='\0')
    return 0;
  return 1+duzina(s+1);
}

int main()
{
  char str[] ="GEEKSFORGEEKS";
  printf("%d", duzina(str));
  return 0;
}
