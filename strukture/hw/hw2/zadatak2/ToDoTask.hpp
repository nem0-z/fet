#pragma once
#include <cstddef>
#include <iostream>

class ToDoTask {
  public:
  
  //Default constructor
  ToDoTask() {
    id_ = generateId();
    printf("Task title: ");
    std::cin.ignore();
    std::getline(std::cin, taskTitle_);
    printf("Task description: ");
    std::getline(std::cin, taskDescription_);
    printf("Priority: ");
    scanf("%lu", &priority_);
  }

  //Constructor with id only
  //Mainly used as a dummy for comparing based on id
  ToDoTask(int id) : id_{id} {}

  //Logical operators
  bool operator<(const ToDoTask& other) const {
    return priority_ < other.priority_;
  }
  bool operator>(const ToDoTask& other) const {
    return priority_ > other.priority_;
  }
  bool operator==(const ToDoTask& other) const { return id_ == other.id_; }

  private:
  int id_;
  std::string taskTitle_;
  std::string taskDescription_;
  size_t priority_;
  //Friend function for printing out content of data structure
  //Implementation included in ToDoTask.cpp file
  friend std::ostream& operator<<(std::ostream&, const ToDoTask&);
  //Id generator
  int generateId() {
    static int counter = 0;
    return ++counter;
  }
};

