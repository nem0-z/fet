#include <bits/stdc++.h>

class StationsInfo
{
    std::string id_;
    double latitude_;
    double longitude_;
    double elevation_;
    std::string city_;
}; // stanica iz jednog grada
class Station
{
    std::string stationdId_;
    Date date_;
    double maxTemp_;
    double minTemp_;
}; //iz stations.csv
class Date
{
public:
    uint8_t year_;
    uint8_t month_;
    char hyphen;
}; //specifican nacin zapis naseg datuma

int findStation(const std::string &) {}
void AnnualInfo(uint8_t) {}
void MonthlyInfo(int, uint8_t) {}

int main()
{
    std::vector<StationsInfo> stations;
    std::ifstream input(stations.csv);
    while (!input.eof())
    {
        StationsInfo station;
        std::string id, city;
        double latitude, longitude, elevation;

        stations.push_back(station);
    }

    uint8_t year, month;
    int choice;
    std::string location, id;
    double mintemp, maxtemp;
    int dummyStation;
    const std::string welcomeMessage = "************* Historical temperature information *************\n";
    std::cout << welcomeMessage;
    while (1)
    {
        std::cout << "\t1. Get information for entire year\n";
        std::cout << "\t2. Get information for specific month\n";
        std::cout << "\t3. Insert new historical temperature information\n";
        std::cout << "\t4. Exit\n";
        std::cout << "Your choice?: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter location: ";
            std::cin >> location;
            auto dummy1 = findStation(location);
            std::cout << "Enter year: ";
            std::cin >> year;
            AnnualInfo(year);
            break;
        }
        case 2:
        {
            std::cout << "Enter location where station is placed: ";
            std::cin >> location;
            auto iter = findStation(location);
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cin >> month;
            MonthlyInfo(dummyStation, month);
            break;
        }

        case 3:
        {
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "Enter month: ";
            std::cin >> month;
            std::cout << "Enter minimal temperature: ";
            std::cin >> mintemp;
            std::cout << "Enter maximum temperature: ";
            std::cin >> maxtemp;
            break;
        }
        case 4:
        {
            return 0;
            break;
        }

        default:
        {
            std::cout << "Wrong input!\n";
        }
        }
    }
    return 0;
}