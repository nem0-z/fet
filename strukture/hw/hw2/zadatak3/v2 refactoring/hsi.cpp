#include "hsi.hpp"

int printMenu(void)
{
    int choice;
    printf("************* Historical temperature information *************\n");
    printf("\t1. Get information for entire year\n");
    printf("\t2. Get information for specific month\n");
    printf("\t3. Insert new historical temperature information\n");
    printf("\t4. Exit\n\n");
    printf("Your choice?: ");
    scanf("%d", &choice);
    return choice;
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

void printTemps(std::list<StationData>::const_iterator it)
{
    if (it->tMax_ == -273.15)
        printf("N/A\t\t");
    else
        printf("%.2f\t\t", it->tMax_);
    if (it->tMin_ == -273.15)
        printf("N/A\n");
    else
        printf("%.2f\n", it->tMin_);
}

Date toDate(const std::string &dateStr)
{
    Date newDate;
    newDate.year_ = std::stoi(dateStr.substr(0, 4));
    newDate.month_ = std::stoi(dateStr.substr(5, 6));
    return newDate;
}

std::list<Station>::iterator findStation(std::list<Station> &stations)
{
    std::string location;
    std::cout << "Enter location where station is placed: ";
    std::cin >> location;
    auto it = findStation(stations, location);
    if (it == stations.end())
    {
        std::cout << "No station found.\n"
                  << std::endl;
        return stations.end();
    }
    it->StationInfo();
    return it;
}

std::list<Station>::iterator findStation(std::list<Station> &stations, const std::string &location)
{
    //Try to find station in existing list of stations
    auto it = std::find_if(stations.begin(), stations.end(), [location](Station &st) { return st.location_ == location; });
    if (it == stations.end())
    {
        //Try to find station in .csv file
        if (!addStationInfo(stations, location))
            return stations.end();
        return addStationData(stations, location);
        //If found, add to existing list of stations and return
    }
    return it;
}

std::list<Station>::iterator checkId(std::list<Station> &stations, const std::string &id)
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
                    std::stringstream ss(line);
                    int i = 0;
                    while (ss.good())
                    {
                        std::getline(ss, token, ',');
                        if (i++ == 4)
                        {
                            addStationInfo(stations, token);
                            return addStationData(stations, token);
                        }
                    }
                }
            }
        }
        return stations.end();
        //Else return end which signals that no station was found
    }
    return it;
    //Ofcourse return iterator to matching station if we found it in our list in the first place
}

bool addStationInfo(std::list<Station> &stations, const std::string &location)
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
            std::stringstream ss(line);
            while (ss.good())
            {
                std::getline(ss, token, ',');
                parser.push_back(token);
            }
            if (parser[4] == location) //If location is found then add it to our list and return
            {
                newStation.id_ = parser[0];
                newStation.lattitude_ = std::stod(parser[1]);
                newStation.longitude_ = std::stod(parser[2]);
                newStation.elevation_ = std::stod(parser[3]);
                newStation.location_ = parser[4];
                stations.push_back(newStation);
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
    //Check if location was found anyway to satisfy compiler in case it doesn't find anything
    return (parser.empty()) ? false : true;
}

std::list<Station>::iterator addStationData(std::list<Station> &stations, const std::string &location)
{
    auto stationIterator = std::find_if(stations.begin(), stations.end(),
                                        [location](const Station &st) { return st.location_ == location; });

    const std::string filename = location + ".csv";
    std::ifstream input(filename);
    //This is fine since this function won't be called unless input of location is valid

    StationData toAdd;
    std::list<StationData> data;
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
                //I mean temps could've just been strings and I initialize them to N/A if empty
                //But meh strings are shit
                parser.push_back(token);
            }
            toAdd.date_ = toDate(parser[0]);
            toAdd.tMax_ = std::stod(parser[1]);
            toAdd.tMin_ = std::stod(parser[2]);
            data.push_back(toAdd);
            parser.clear();
        }
    }
    stationIterator->data_ = data;
    return stationIterator;
}

void EditStation(std::list<Station> &stations)
{
    std::string id;
    int year, month;
    double min, max;
    std::cout << "Enter id: ";
    std::cin >> id;
    auto it = checkId(stations, id);
    if (it == stations.end())
    {
        std::cout << "Station does not exist." << std::endl;
        return;
    }
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter min temperature: ";
    std::cin >> min;
    std::cout << "Enter max temperature: ";
    std::cin >> max;
    EditStation(it, year, month, min, max);
}

void EditStation(std::list<Station>::iterator it, int year, int month, double min, double max)
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
            it->data_.insert(findYear, toAdd);
        }
        //If it's existing year then iterate until matching month
        else
        {
            auto findSpot = std::find_if(it->data_.begin(), it->data_.end(), [year](StationData &st) { return year < st.date_.year_; });
            it->data_.insert(findSpot, toAdd);
        }
        //push_back or push_front based on the year if it's new minimum or new maximum
        //I think I covered all cases lol
    }
}
void Station::AnnualInfo(int year) const
{
    std::cout << year << std::endl;
    auto it = std::find_if(data_.begin(), data_.end(), [year](const StationData &st) { return st.date_.year_ == year; });
    if (it == data_.end())
    {
        std::cout << "No record for this period." << std::endl;
        return;
    }
    int i = 1;
    int thisYear = it->date_.year_;
    printf("\nMonth\tMax temp\tMin temp\n---------------------------------\n");
    while (i <= 12)
    {
        printMonth(i);
        printf("\t");
        if (it->date_.year_ != thisYear || it->date_.month_ != i)
        {
            std::cout << "N/A\t\tN/A\n";
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
        std::cout << "No record for this period." << std::endl;
        return;
    }
    printf("Max temp\tMin temp\n-------------------------\n");
    printTemps(it);
    printf("\n");
}

void Station::StationInfo() const
{
    std::cout << "StationID: " << id_ << '\n';
    printf("Lattitude: %.4f\nLongitude: %.4f\nElevation: %0.f\n", lattitude_, longitude_, elevation_);
    //Yes I don't like std::cout :D
}
