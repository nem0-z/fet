#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <cstddef>
#include <utility>
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
    std::string id_ = "NULL";
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
void EditStation(std::vector<Station> &);
std::vector<Station>::iterator findStation(std::vector<Station> &, const char *);
void printTemps(std::vector<StationData>::const_iterator);
Date toDate(const std::string &);
//Stupid funs
void EditStation(std::vector<Station>::iterator, int, int, double, double);
bool addStationInfo(std::vector<Station> &, const std::string &);
std::vector<Station>::iterator findStation(std::vector<Station> &, const std::string &);
std::vector<Station>::iterator addStationData(std::vector<Station> &, const std::string &);
std::vector<Station>::iterator checkId(std::vector<Station> &, const std::string &);
