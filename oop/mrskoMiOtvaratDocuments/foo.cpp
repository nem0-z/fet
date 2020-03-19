#include <iostream>

void getSize(int (&x)[10]){
  x[5] = 400;
}

int main(int argc, char *argv[])
{
  int px[10];
  getSize(px);
  // std::cout << getSize(px) << std::endl;
  // int* p = new int[5];
  for(int i = 0; i<sizeof(px)/sizeof(int); ++i)
  {
  //   // *(p+i) = 10;
  //   p[i] = 10;
  //   // px[i] = 10;
    std::cout<<px[i]<<" ";
  }
  std::cout<<'\n';
  return 0;
}
