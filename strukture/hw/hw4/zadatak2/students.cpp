#include "students.hpp"

void retardInput()
{
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Nice try" << std::endl;
}
int printMenu()
{
    int choice;
    const std::string decor(20, '*');
    std::cout << decor << std::endl;
    std::cout << "1.Add new student" << std::endl;
    std::cout << "2.Erase student" << std::endl;
    std::cout << "3.Show all students" << std::endl;
    std::cout << "4.Show one student" << std::endl;
    std::cout << "Your choice: ";
    if (std::cin >> choice)
        return choice;
    else
        retardInput();
    return -1;
}

void Students::addStudent()
{
    int i;
    std::string s, n;
    double grade;
    std::cout << "Enter data: " << std::endl;
    std::cin >> i >> n >> s >> grade;
    Student tmp{i, n, s, grade};
    auto success = students_.insert(tmp);
    if (!(success.second))
        throw std::logic_error("Konjino");
}
void Students::eraseStudent()
{
    int ind;
    std::cout << "Index number: " << std::endl;
    if (std::cin >> ind)
    {
        erase(ind);
    }
    else
        retardInput();
}
void Students::printStudents() const
{
    for (const auto &item : students_)
    {
        std::cout << item;
    }
}
void Students::printStudent() const
{
}

std::ostream &operator<<(std::ostream &stream, const Students::Student &student)
{

    stream << "Prezime: " << student.surname << std::endl;
    stream << "Ime: " << student.name << std::endl;
    stream << "Index number: " << student.index << std::endl;
    stream << "Average grade: " << student.avgGrade << std::endl;
    stream << std::endl;
    return stream;
}