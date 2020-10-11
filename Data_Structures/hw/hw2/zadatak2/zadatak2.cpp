#include <iostream>
#include "ToDoTask.hpp"

int main(void)
{
  sorted_list<ToDoTask> list;
  while (1)
  {
    int choice = printMenu();
    if (choice == 1)
    {
      addTask(list);
    }
    else if (choice == 2)
    {
      list.print();
    }
    else if (choice == 3)
    {
      markAsDone(list);
    }
    else if (choice == 4)
    {
      lowPriority(list);
    }
    else if (choice == 5)
    {
      highPriority(list);
    }
    // Didn't understand if 4 & 5 are supposed to be one option
    // It's just matter of putting those 2 loops together though :D
    else if (choice == 6)
    {
      std::cout << "Exiting..." << std::endl;
      return 1;
    }
    else
    {
      std::cout << "Bad input!" << std::endl;
    }
  }
  return 0;
}
