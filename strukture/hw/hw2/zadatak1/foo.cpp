#include <iostream>
#include <stddef.h>
#include <list>

#include "sorted_list.hpp"

int main(void)
{
  sorted_list<int32_t> lista;
  for(int i = 1; i < 101; i+=10){
    lista.add(i);
  }
  lista.add(-5);
  lista.add(14);
  lista.add(75);
  lista.add(150);
  lista.print();
  int32_t num = 150;
 auto it =  lista.find_if([num](int32_t broj){return broj == num;});
 std::cout << *it << std::endl;
 lista.remove(it);
 lista.print();
 std::cout << lista.size() << std::endl;
 std::cout << lista.empty() << std::endl;
 lista.clear();
 std::cout << lista.size() << std::endl;
 std::cout << lista.empty() << std::endl;

  return 0;
}
