#include "hsi.hpp"

void retardInput()
{
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Nice try" << std::endl;
    return;
}

int printMenu(void)
{
    using std::cout;
    int choice = -1;
    const std::string decor(15, '*');
    cout << decor << "Historical temperature information" << decor << std::endl;
    cout << "\t1. Get information for entire year\n";
    cout << "\t2. Get information for specific month\n";
    cout << "\t3. Insert new historical temperature information\n";
    cout << "\t4. Exit\n\n";
    cout << "Your choice?: ";
    if (std::cin >> choice)
    {
        return choice;
    }
    else
    {
        retardInput();
        return -1;
    }
}

void printMonth(int monthNr)
{
    using std::cout;
    if (monthNr == 1)
        cout << "Jan";
    else if (monthNr == 2)
        cout << "Feb";
    else if (monthNr == 3)
        cout << "Mar";
    else if (monthNr == 4)
        cout << "Apr";
    else if (monthNr == 5)
        cout << "May";
    else if (monthNr == 6)
        cout << "Jun";
    else if (monthNr == 7)
        cout << "Jul";
    else if (monthNr == 8)
        cout << "Aug";
    else if (monthNr == 9)
        cout << "Sep";
    else if (monthNr == 10)
        cout << "Oct";
    else if (monthNr == 11)
        cout << "Nov";
    else if (monthNr == 12)
        cout << "Dec";
}

void printTemps(const std::vector<StationData>::const_iterator &it)
{
    using std::cout;
    if (it->tMax_ == -273.15)
        printf("N/A\t\t");
    else
        cout << it->tMax_ << "\t\t";
    if (it->tMin_ == -273.15)
        printf("N/A\n");
    else
        cout << it->tMin_ << "\n";
}

Date toDate(std::string &&dateStr)
{
    Date newDate;
    newDate.year_ = std::stoi(dateStr.substr(0, 4));
    newDate.month_ = std::stoi(dateStr.substr(5, 6));
    return newDate;
}

void stationInfo(int choice, std::vector<Station> &stations)
{
    int year, month;
    auto it = findStation(stations);
    if (it == stations.end())
        return;
    std::cout << "Enter year: ";
    if (std::cin >> year)
    {
        if (choice == 1)
        {
            it->AnnualInfo(year);
        }
        else
        {
            std::cout << "Enter month: ";
            if (std::cin >> month)
                it->MonthlyInfo(year, month);
            else
                retardInput();
        }
    }
    else
        retardInput();
    return;
}

std::vector<Station>::iterator findStation(std::vector<Station> &stations)
{
    std::string location;
    printf("Enter location where station is placed: ");
    std::cin.ignore();
    std::getline(std::cin,location);
    auto it = findStation(stations, std::move(location));
    if (it == stations.end())
    {
        printf("No station found.\n\n");
        return stations.end();
    }
    it->StationInfo();
    return it;
}

std::vector<Station>::iterator findStation(std::vector<Station> &stations, std::string &&location)
{
    //Try to find station in existing list of stations
    auto it = std::find_if(stations.begin(), stations.end(), [location](Station &st) { return st.location_ == location; });
    if (it == stations.end())
    {
        //Try to find station in .csv file
        if (!addStationInfo(stations, std::move(location)))
            return stations.end();
        return addStationData(stations, std::move(location));
        //If found, add to existing list of stations and return
    }
    return it;
}

std::vector<Station>::iterator checkId(std::vector<Station> &stations, std::string &&id)
{
    auto it = std::find_if(stations.begin(), stations.end(), [id](Station &st) { return st.id_ == id; });
    if (it == stations.end())
    {
        std::ifstream input("stations.csv");
        std::string line, token;
        while (!input.eof())
        {
            while (std::getline(input, line, '\n'))
            {
                if (line.substr(0, 11) == id) //If matching id then add that station
                {
                    std::stringstream ss(std::move(line));
                    int i = 0;
                    while (ss.good())
                    {
                        std::getline(ss, token, ',');
                        if (i++ == 4)
                        {
                            addStationInfo(stations, std::move(token));
                            return addStationData(stations, std::move(token));
                        }
                    }
                }
            }
        }
        return stations.end();
        //Else return end which signals that no station was found
        input.close();
    }
    return it;
    //Ofcourse return iterator to matching station if we found it in our list in the first place
}

bool addStationInfo(std::vector<Station> &stations, std::string &&location)
{
    std::ifstream input("stations.csv");
    Station newStation;
    std::vector<std::string> parser;

    std::string line, token;
    std::getline(input, line, '\n'); //Ignore header
    while (!input.eof())
    {
        while (std::getline(input, line, '\n'))
        {
            std::stringstream ss(std::move(line));
            while (ss.good())
            {
                std::getline(ss, token, ',');
                parser.push_back(std::move(token));
            }
            if (parser[4] == location) //If location is found then add it to our list and return
            {
                newStation.id_ = std::move(parser[0]);
                newStation.lattitude_ = std::stod(std::move(parser[1]));
                newStation.longitude_ = std::stod(std::move(parser[2]));
                newStation.elevation_ = std::stod(std::move(parser[3]));
                newStation.location_ = std::move(parser[4]);
                stations.push_back(std::move(newStation));
                return true;
            }
            parser.clear();
            //We can let it push_back into that vector since it's O(1) meh it's quick i guess
            //I am guessing wrong because using string is retarded since it fucks with heap a lot
            //I mean this is a bit stupid but I am stupid aswell and thinking
            //it will atleast insure in some cases we don't have to go through whole list of stations
            //We will have linear complexity in worst case(if adding the last station)
            //which is fine I guess since we can't use anything better RIP
        }
    }
    input.close();
    //Check if location was found anyway to satisfy compiler in case it doesn't find anything
    return (parser.empty()) ? false : true;
}

std::vector<Station>::iterator addStationData(std::vector<Station> &stations, std::string &&location)
{
    auto stationIterator = std::find_if(stations.begin(), stations.end(),
                                        [location](const Station &st) { return st.location_ == location; });

    const std::string filename = location + ".csv";
    std::ifstream input(filename);
    //This is fine since this function won't be called unless input of location is valid

    StationData toAdd;
    std::vector<StationData> data;
    std::vector<std::string> parser;

    std::string line, token;
    std::getline(input, line, '\n'); //Ignore header
    while (!input.eof())
    {
        while (std::getline(input, line, '\n'))
        {
            std::stringstream ss(line);
            int i = 0;
            while (ss.good())
            {
                std::getline(ss, token, ',');
                if (i++ == 0)
                {
                    continue;
                } //Skip adding station id, no need
                if (token.empty())
                {
                    token = "-273.15";
                } //If there is no temperature then set it to -273.15(treat accordingly)
                //I hope we won't be reaching those temps in real life soon :D
                parser.push_back(std::move(token));
            }
            toAdd.date_ = toDate(std::move(parser[0]));
            toAdd.tMax_ = std::stod(std::move(parser[1]));
            toAdd.tMin_ = std::stod(std::move(parser[2]));
            data.push_back(std::move(toAdd));
            parser.clear();
        }
    }
    stationIterator->data_ = data;
    input.close();
    return stationIterator;
}

void updateStation(std::vector<Station> &stations)
{
    std::string id;
    int year, month;
    double min, max;
    printf("Enter id: ");
    if (std::cin >> id)
    {
        auto it = checkId(stations, std::move(id));
        if (it == stations.end())
        {
            printf("Station does not exist.\n");
            return;
        }
        printf("Enter year: ");
        if (std::cin >> year)
        {
            printf("Enter month: ");
            if (std::cin >> month)
            {
                if (month < 1 || month > 12)
                {
                    printf("Nice try.\n");
                    return;
                }
                printf("Enter min temperature: ");
                std::cin >> min;
                printf("Enter max temperature: ");
                std::cin >> max;
                editStation(it, year, month, min, max);
            }
            else
                retardInput();
        }
        else
            retardInput();
    }
    else
        retardInput();
    return;
}

void editStation(std::vector<Station>::iterator it, int year, int month, double min, double max)
{
    auto findDate = std::find_if(it->data_.begin(), it->data_.end(),
                                 [year, month](StationData &st) { return st.date_.year_ == year && st.date_.month_ == month; });
    if (findDate != it->data_.end())
    {
        findDate->tMax_ = max;
        findDate->tMin_ = min;
    }
    //Try to find already existing date
    else
    {
        StationData toAdd{{year, month}, max, min}; //Anyhow we will be adding something new
        auto findYear = std::find_if(it->data_.begin(), it->data_.end(), [year](StationData &st) { return st.date_.year_ == year; });
        if (findYear != it->data_.end())
        {
            while (findYear->date_.month_ < month && findYear->date_.year_ == year)
            {
                ++findYear;
            }
            it->data_.insert(findYear, std::move(toAdd));
        }
        //If it's existing year then iterate until matching month
        else
        {
            auto findSpot = std::find_if(it->data_.begin(), it->data_.end(), [year](StationData &st) { return year < st.date_.year_; });
            it->data_.insert(findSpot, std::move(toAdd));
        }
        //push_back or push_front based on the year if it's new minimum or new maximum
        //I think I covered all cases lol
    }
}
void Station::AnnualInfo(int year) const
{
    std::cout << "Record for year: " << year << std::endl;
    auto it = std::find_if(data_.begin(), data_.end(), [year](const StationData &st) { return st.date_.year_ == year; });
    if (it == data_.end())
    {
        printf("No record for this period.\n");
        return;
    }
    int i = 1;
    int thisYear = it->date_.year_;
    const std::string decor(35, '-');
    std::cout << "\nMonth\tMax temp\tMin temp\n"
              << decor << std::endl;
    while (i <= 12)
    {
        printMonth(i);
        printf("\t");
        if (it->date_.year_ != thisYear || it->date_.month_ != i)
        {
            printf("N/A\t\tN/A\n");
            ++i;
            continue;
        }
        printTemps(it++);
        ++i;
    }
    printf("\n");
}

void Station::MonthlyInfo(int year, int month) const
{
    auto it = std::find_if(data_.begin(), data_.end(),
                           [year, month](const StationData &st) { return st.date_.year_ == year && st.date_.month_ == month; });
    if (it == data_.end())
    {
        printf("No record for this period.\n");
        return;
    }
    const std::string decor(25, '-');
    std::cout << "Max temp\tMin temp\n"
              << decor << std::endl;
    printTemps(it);
    printf("\n");
}

void Station::StationInfo() const
{
    std::cout << "StationID: " << id_ << '\n';
    std::cout << "Lattitude: " << lattitude_ << "\nLongitude: " << longitude_ << "\nElevation: " << elevation_ << std::endl;
}
