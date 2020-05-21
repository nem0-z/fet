#include "students.hpp"

int main(void)
{
	Students s;
	int choice = -1;
	while (1)
	{
		choice = printMenu();
		if (choice == 1)
		{
			s.addStudent();
		}
		else if (choice == 2)
		{
		}
		else if (choice == 3)
		{
			s.printStudents();
		}
		else if (choice == 4)
		{
		}
		else if (choice == 5)
		{
		}
	}
	return 0;
}
