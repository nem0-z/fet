#include "ToDoTask.hpp"

std::ostream &operator<<(std::ostream &stream, const ToDoTask &task)
{
  stream << "Task id:";
  stream << task.id_ << std::endl;
  stream << "Task title:";
  stream << task.taskTitle_ << std::endl;
  stream << "Task description:";
  stream << task.taskDescription_ << std::endl;
  stream << "Task priority:";
  stream << task.priority_ << std::endl;
  stream << '\n';
  return stream;
}

void retardInput()
{
  std::cin.clear();
  std::cin.ignore(100, '\n');
  std::cout << "Nice try" << std::endl;
  return;
}

int printMenu()
{
  int choice = -1;
  const std::string decor(40, '-');
  std::cout << decor << std::endl;
  std::cout << "1) Add new task" << std::endl;
  std::cout << "2) Show all tasks" << std::endl;
  std::cout << "3) Mark as done" << std::endl;
  std::cout << "4) Show 3 highest-priority tasks" << std::endl;
  std::cout << "5) Show 3 lowest-priority tasks" << std::endl;
  std::cout << "6) Exit" << std::endl;
  std::cout << "\nEnter your choice: ";
  if (std::cin >> choice)
    return choice;
  else
  {
    retardInput();
    return -1;
  }
}

void addTask(sorted_list<ToDoTask> &list)
{
  std::string title, desc;
  size_t priority;
  std::cout << "Task title: ";
  std::cin.ignore();
  std::getline(std::cin, title);
  std::cout << "Task description: ";
  std::getline(std::cin, desc);
  std::cout << "Priority: ";
  if (std::cin >> priority)
  {
    list.add(ToDoTask{std::move(title), std::move(desc), priority});
    std::cout << "Task successfully added." << std::endl;
  }
  else
  {
    retardInput();
    std::cout << "Priority has to be an integer." << std::endl;
  }
  return;
}

void markAsDone(sorted_list<ToDoTask> &list)
{
  int id;
  std::cout << "Task id: ";
  if (std::cin >> id)
  {
    auto it = list.find(ToDoTask{id});
    if (it != list.end())
    {
      list.remove(it);
      std::cout << "Task #" << id << " removed." << std::endl;
    }
    else
    {
      std::cout << "Task #" << id << " not found." << std::endl;
    }
  }
  else
  {
    retardInput();
    std::cout << "ID is a non-negative integer." << std::endl;
  }
  return;
}

void lowPriority(sorted_list<ToDoTask> &list)
{
  if (list.size() <= 3)
    list.print();
  else
  {
    auto it = list.begin();
    for (int i = 0; i < 3; ++i, ++it)
    {
      std::cout << *it << std::endl;
    }
  }
}

void highPriority(sorted_list<ToDoTask> &list)
{
  if (list.size() <= 3)
    list.print();
  else
  {
    auto it = --list.end();
    for (int i = 0; i < 3; ++i, --it)
    {
      std::cout << *it << std::endl;
    }
  }
}