#include <assert.h>
#include <stdio.h>

int maxArr(const int* array, size_t size) {
  assert(array != NULL && "Error!");  // i c++ exceptioni koriste c asserte
  int max_ = 0;
  for (int i = 0; i < size; ++i)
    if (array[i] > max_) max_ = array[i];
  return max_;
}

int main(void) {
  const int size = 10;
  int array[size] = {5, 4, 2, 1, 6, 7, 2, 14, 3};
  printf("%d", maxArr(array, size));
  return 0;
}

// ecc -target mips32r2el-linux -O0 -g file.c -o progName
// qemu-mipsel progName
// qemu-mipsel -g 1234 (bilo kakav broj veci od 1000) progName&
// ps aux | grep qemu i onda kill -9 id (od procesa)
// gdb-multiarch progName  -q (quiet, da ne izbacuje neke licence i gluposti) ->debugger 
// target remote :1234 (bilo kakav broj veci od 1000 ali da je isti ko ovaj odozgo hehe)
// b main -> napravi breakpoint
// c ->continue
// list  -> da pokaze ovaj nas kod al ruzno brate
// tui enable  -terminal user interface, malo da ljepse pokaze ovaj nas kod
// si -> single instruction
// ni -> next instruction
// p array -> ispisi array
// b 15 -> postavi breakpoint u 15-oj liniji
// set array[1] = 10; //setuje drugi u nizu na 10 npr
// layout regs
//  $ dereferencira registre
//  x(kao examine)/10(broj lokacija koje hocemo pogledati)
//  w(32 bita, l za 64, h za 16,...) array
//  x/10i $pc -> dissassemble iducih 10 funkcija
