#pragma once
#include <cstddef>
#include <iostream>

class ToDoTask {
  public:
  // Default constructor
  ToDoTask() {
    id_ = generateId();
    printf("Task title: ");
    std::cin.ignore();
    std::getline(std::cin, taskTitle_);
    printf("Task description: ");
    std::getline(std::cin, taskDescription_);
    printf("Priority: ");
    std::cin >> priority_;
    std::cout << "Task successfully added" << std::endl;
    std::cin.clear();
  }

  ToDoTask(const std::string& title, const std::string& desc, size_t prior):
    taskTitle_{title},taskDescription_{desc},priority_{prior}
  {
    id_ = generateId();
  }

  // Constructor with id only
  // Use as a dummy for comparing based on id
  ToDoTask(int id) : id_{id} {}

  // Logical operators
  bool operator<=(const ToDoTask& other) const {
    return priority_ >= other.priority_;
  }
  bool operator>=(const ToDoTask& other) const {
    return priority_ <= other.priority_;
  }
  bool operator<(const ToDoTask& other) const {
    return priority_ > other.priority_;
  }
  bool operator>(const ToDoTask& other) const {
    return priority_ < other.priority_;
  }
  // Other way around because sorted_list sorts in ascending order
  bool operator==(const ToDoTask& other) const { return id_ == other.id_; }

  private:
  int id_ = 0;
  std::string taskTitle_;
  std::string taskDescription_;
  size_t priority_ = 0;
  // Friend function for printing out content of data structure
  // Implementation included in ToDoTask.cpp file
  friend std::ostream& operator<<(std::ostream&, const ToDoTask&);
  // Id generator
  int generateId() {
    static int counter = 0;
    return ++counter;
  }
};

