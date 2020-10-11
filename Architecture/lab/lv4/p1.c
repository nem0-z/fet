#include<stdint.h> //za ove intove

const int16_t niz[10] = {12, 3, -9, 1200, -2400, 490, 800, -23, 5, 22};
int suma;
int16_t najmanji;

int main(int argc, char *argv[])
{
  int i = 0;
  int min = niz[0];
  while(i<10){
    suma=suma+niz[i];
    if (niz[i]<min) min = niz[i];
    ++i;
  }
  najmanji = min;
  return 0;
}
