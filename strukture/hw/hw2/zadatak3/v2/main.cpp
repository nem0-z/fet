#include <iostream>
#include "hsi.hpp"

int main(int argc, char const *argv[])
{
    std::list<Station> stations;
    int year, month;
    std::string location;
    while (1)
    {
        int choice = printMenu();
        if (choice == 1 || choice == 2)
        {
            std::cout << "Enter location where station is placed: ";
            std::cin >> location;
            auto it = findStation(stations, location);
            if (it == stations.end())
            {
                std::cout << "No station found for that location\n"
                          << std::endl;
                continue;
            }
            it->StationInfo();
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
            printf("Wrong input\n");
        }
    }

    return 0;
}
