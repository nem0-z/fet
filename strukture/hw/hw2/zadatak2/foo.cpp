#include <iostream>
#include "ToDoTask.hpp"
#include "sorted_list.hpp"

int main(void) {
  sorted_list<ToDoTask> lista;
  // // ToDoTask task;
  // // ToDoTask task1;
  // // lista.add(task);
  // // lista.add(task1);
  // // std::cout << lista.size() << std::endl;
  // // std::cout << task.operator<(task1);
  for(int i = 0; i<20; ++i)
    lista.add(ToDoTask{i});
  lista.print();
  // sorted_list<int> lista;
  // for(int i = 0; i<1000; ++i)
  //   lista.add(1);
  // lista.print();
  return 0;
}
