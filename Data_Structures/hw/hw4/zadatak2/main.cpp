#include "students.hpp"

int main(void) {
  Students s;
  int choice = -1;
  while (1) {
    try {
      choice = printMenu();
      if (choice == 1)
        s.addStudent();
      else if (choice == 2)
        s.eraseStudent();
      else if (choice == 3)
        s.printStudents();
      else if (choice == 4)
        s.printStudent();
      else if (choice == 5)
        break;
    } catch (const std::runtime_error& err) {
      std::cout << err.what() << std::endl;
    }
  }
  return 0;
}
