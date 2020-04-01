/* Napisati rekurziju u MIPS assembly  */
/* koja provjerava da li je proslijedjeni string palindrom */
#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int len); /* {
*   if(len<2) */
/*     return 1; */
/*   else */
/*     return s[0] == s[len-1] && isPalindrome(s+1, len -2); */
/* } */

int main(void)
{
  char niz[50] = "rotor";
  if(isPalindrome(niz,strlen(niz))) 
    printf("Palindrom!\n");
    else
      printf("Nije palindrom!\n");
  return 0;
}
