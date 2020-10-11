#pragma once
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

class Students {
  public:
  void addStudent();
  void eraseStudent();
  void printStudents() const;
  void printStudent() const;

  private:
  class Student {
public:
    int index;
    std::string name;
    double avgGrade;
  };
  std::unordered_map<int, Student> students_;
  void eraseMember(int);
  void printMember(
      const std::unordered_map<int, Student>::const_iterator&) const;
  void printMember(const std::pair<int, Student>&) const;
};

void retardInput();
int printMenu();
