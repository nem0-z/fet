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
            stationInfo(choice, stations);
        }

        else if (choice == 3)
        {
            updateStation(stations);
        }
        else if (choice == 4)
        {
            return 0;
        }
        else
        {
            std::cout << "Bad input" << std::endl;
        }
    }

    return 0;
}
