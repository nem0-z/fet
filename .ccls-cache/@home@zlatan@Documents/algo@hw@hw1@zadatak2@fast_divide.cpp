#include <iostream>

int fast_divide(int x, int y){
  //x = 696
  //y = 29
  static int i = 1;
  if(y>=x) return 0;
  //x-y
  i = i << 1;
  fast_divide(x,y+y);


  fast_divide(
}

int main(void){
  std::cout << fast_divide(24,8) << std::endl;
  return 0;
}
