#include <iostream>
#include "hsi.hpp"

int main(int argc, char const *argv[])
{
    std::vector<Station> stations;
    int year, month;
    while (1)
    {
        int choice = printMenu();
        if (choice == 1 || choice == 2)
        {
            auto it = findStation(stations);
            if (it == stations.end())
                continue;
            std::cout << "Enter year: ";
            std::cin >> year;
            if (choice == 1)
            {
                it->AnnualInfo(year);
            }
            else
            {
                std::cout << "Enter month: ";
                std::cin >> month;
                it->MonthlyInfo(year, month);
            }
        }
        else if (choice == 3)
        {
            EditStation(stations);
        }
        else if (choice == 4)
        {
            return 0;
        }
        else
        {
            std::cout << "Wrong input" << std::endl;
        }
    }

    return 0;
}
