#pragma once
#include <cstddef>
#include <iostream>
#include "sorted_list.hpp"

class ToDoTask
{
public:
  ToDoTask() = default;

  ToDoTask(std::string &&title, std::string &&desc, size_t priority)
      : taskTitle_{std::move(title)}, taskDescription_{std::move(desc)}, priority_{priority}
  {
    id_ = generateId();
  }

  // Constructor with id only
  // Used as a dummy for comparing based on id
  ToDoTask(int id) : id_{id} {}

  // Logical operators
  bool operator<=(const ToDoTask &other) const
  {
    return priority_ >= other.priority_;
  }
  bool operator>=(const ToDoTask &other) const
  {
    return priority_ <= other.priority_;
  }
  bool operator<(const ToDoTask &other) const
  {
    return priority_ > other.priority_;
  }
  bool operator>(const ToDoTask &other) const
  {
    return priority_ < other.priority_;
  }
  // Other way around because sorted_list sorts in ascending order
  bool operator==(const ToDoTask &other) const { return id_ == other.id_; }

private:
  int id_ = 0;
  std::string taskTitle_;
  std::string taskDescription_;
  size_t priority_ = 0;
  // Friend function for printing out content of data structure
  // Implementation included in ToDoTask.cpp file
  friend std::ostream &operator<<(std::ostream &, const ToDoTask &);
  // Id generator
  int generateId()
  {
    static int counter = 0;
    return ++counter;
  }
};

int printMenu();
void retardInput();
void addTask(sorted_list<ToDoTask> &);
void markAsDone(sorted_list<ToDoTask> &);
void lowPriority(sorted_list<ToDoTask> &);
void highPriority(sorted_list<ToDoTask> &);
