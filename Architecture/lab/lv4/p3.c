/* napisati funkciju myabs koja uzima dva argumenta: */
/* 1.adresa na koji ce smjestiti rezultat */
/* 2.broj koji treba transformirati u njegovu aps vrijednost */
/* i rezultat snimiti na adresu na koju pokazuje prvi arg */

void myabs(int*,int);

int main(int argc, char *argv[])
{
  int res, num = -5;
  myabs(&res,num);
  return 0;
}

//nm -u objektnifajl.o -> koji su undefined simboli u objektnifajl.o
