#pragma once
#include <iostream>
#include <string>
#include <set>
#include <stdexcept>

class Students
{

private:
	class Student
	{
	public:
		int index;
		std::string name;
		std::string surname;
		//opcionalno stavi jedan string ime prezime
		double avgGrade;
		bool operator<(const Student &s) const
		{
			return surname < s.surname;
		}
	};
	std::set<Student> students_;

public:
	void addStudent();
	void eraseStudent();
	void printStudents() const;
	void printStudent() const;
	friend std::ostream &operator<<(std::ostream &stream, const Student &student);
};

void retardInput();
int printMenu();
