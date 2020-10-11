#include "students.hpp"

void retardInput() {
  std::cin.clear();
  std::cin.ignore(100, '\n');
  std::cout << "Nice try" << std::endl;
}

int printMenu() {
  int choice;
  const std::string decor(20, '*');
  std::cout << decor << std::endl;
  std::cout << "1.Add new student" << std::endl;
  std::cout << "2.Erase student" << std::endl;
  std::cout << "3.Show all students" << std::endl;
  std::cout << "4.Search" << std::endl;
  std::cout << "5.Exit" << std::endl;
  std::cout << "Your choice: ";
  if (std::cin >> choice)
    return choice;
  else
    retardInput();
  return -1;
}

void Students::addStudent() {
  int i;
  std::string s;
  double a;
  std::cout << "Enter index number: ";
  if (std::cin >> i) {
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, s);
    std::cout << "Enter average grade: ";
    if (std::cin >> a) {
      Student st{i, s, a};
      auto success = students_.insert(std::make_pair(i, std::move(st)));
      if (!success.second)
        throw std::runtime_error("Student already exists in database.");
    } else
      retardInput();
  } else
    retardInput();
}
void Students::eraseStudent() {
  int ind;
  std::cout << "Index number: " << std::endl;
  if (std::cin >> ind) {
    eraseMember(ind);
  } else
    retardInput();
}
void Students::printStudent() const {
  int stnum;
  std::string stname;
  std::cout << "1.Search by index number\n2.Search by name" << std::endl;
  std::cout << "Your choice:";
  if (std::cin >> stnum) {
    if (stnum == 1) {
      std::cout << "Index number:";
      if (std::cin >> stnum) {
        auto found = students_.find(stnum);
        if (found != students_.end())
          printMember(found);
        else
          std::cout << "Student not found" << std::endl;
      } else
        retardInput();
    } else if (stnum == 2) {
      std::cout << "Name:";
      std::cin >> stname;
      bool flag = false;
      for (const auto& s : students_) {
        if (s.second.name == stname) {
          printMember(s);
          flag = true;
        }
      }
      if (!flag) std::cout << "Student not found" << std::endl;
    } else
      throw std::runtime_error("Bad input.");
  } else
    retardInput();
}

void Students::printStudents() const {
  if (students_.empty()) {
    std::cout << "No students in database" << std::endl;
    return;
  }
  for (const auto& s : students_) printMember(s);
}

void Students::printMember(
    const std::unordered_map<int, Student>::const_iterator& item) const {
  std::cout << "Student: " << item->second.name << std::endl;
  std::cout << "Index number: " << item->second.index << std::endl;
  std::cout << "Average grade: " << item->second.avgGrade << std::endl;
  std::cout << std::endl;
}

void Students::printMember(const std::pair<int, Student>& item) const {
  std::cout << "Student: " << item.second.name << std::endl;
  std::cout << "Index number: " << item.second.index << std::endl;
  std::cout << "Average grade: " << item.second.avgGrade << std::endl;
  std::cout << std::endl;
}

void Students::eraseMember(int indexNr) {
  auto found = students_.find(indexNr);
  if (found == students_.end()) throw std::runtime_error("Student not found.");
  char sure = -1;
  std::cout << "Are you sure you want to delete this student? (y/n)"
            << std::endl;
  std::cin >> sure;
  if (sure == 'y' || sure == 'Y') students_.erase(found);
}

