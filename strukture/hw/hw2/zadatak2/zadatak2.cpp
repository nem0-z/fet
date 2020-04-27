#include <iostream>
#include "ToDoTask.hpp"
#include "sorted_list.hpp"
//Make sure you compile together with ToDoTask.cpp

int printMenu()
{
  int choice = -1;
  std::cout << "\n######################" << std::endl;
  std::cout << "1) Add new task" << std::endl;
  std::cout << "2) Show all tasks" << std::endl;
  std::cout << "3) Mark as done" << std::endl;
  std::cout << "4) Show 3 highest-priority tasks" << std::endl;
  std::cout << "5) Show 3 lowest-priority tasks" << std::endl;
  std::cout << "6) Exit" << std::endl;
  std::cout << "\nEnter your choice: ";
  std::cin >> choice;
  return choice;
}

int main(void)
{
  sorted_list<ToDoTask> lista;
  while (1)
  {
    int choice = printMenu();
    if (choice == 1)
    {
      lista.add(ToDoTask{});
      std::cout << "Task successfully added" << std::endl;
    }
    if (choice == 2)
    {
      lista.print();
    }
    if (choice == 3)
    {
      int id;
      std::cout << "Task id: ";
      std::cin >> id;
      auto it = lista.find(ToDoTask{id});
      if (it != lista.end())
      {
        lista.remove(it);
        std::cout << "Task " << id << " removed." << std::endl;
      }
      else
      {
        std::cout << "Task " << id << " not found." << std::endl;
      }
    }
    if (choice == 4)
    {
      if (lista.size() <= 3)
        lista.print();
      else
      {
        auto it = lista.begin();
        for (int i = 0; i < 3; ++i, ++it)
        {
          std::cout << *it << std::endl;
        }
      }
    }
    if (choice == 5)
    {
      if (lista.size() <= 3)
        lista.print();
      else
      {
        auto it = --lista.end();
        for (int i = 0; i < 3; ++i, --it)
        {
          std::cout << *it << std::endl;
        }
      }
    }
    //Didn't understand if 4 & 5 are supposed to be one option
    //It's just matter of putting those 2 loops together though :D
    if (choice == 6)
    {
      return 1;
    }
  }
  return 0;
}
