#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

class Date
{
public:
    int year_;
    int month_;
};

class StationData
{
public:
    Date date_;
    double tMax_;
    double tMin_;
};

class Station
{
public:
    std::string id_;
    double lattitude_;
    double longitude_;
    double elevation_;
    std::string location_;
    std::vector<StationData> data_;
    void AnnualInfo(int) const;
    void MonthlyInfo(int, int) const;
    void StationInfo() const;
};

int printMenu();
void printMonth(int);
void retardInput();
void updateStation(std::vector<Station> &);
void stationInfo(int, std::vector<Station> &);
std::vector<Station>::iterator findStation(std::vector<Station> &);
void printTemps(const std::vector<StationData>::const_iterator &);
Date toDate(std::string &&);
//Stupid funs
void editStation(std::vector<Station>::iterator, int, int, double, double);
bool addStationInfo(std::vector<Station> &, std::string &&);
std::vector<Station>::iterator findStation(std::vector<Station> &, std::string &&);
std::vector<Station>::iterator addStationData(std::vector<Station> &, std::string &&);
std::vector<Station>::iterator checkId(std::vector<Station> &, std::string &&);
