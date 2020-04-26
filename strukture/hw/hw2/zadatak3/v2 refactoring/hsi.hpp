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
#include <forward_list>

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
    std::list<StationData> data_;
    void AnnualInfo(int) const;
    void MonthlyInfo(int, int) const;
    void StationInfo() const;
};

int printMenu();
void printMonth(int);
void EditStation(std::list<Station> &);
std::list<Station>::iterator findStation(std::list<Station> &);
void printTemps(std::list<StationData>::const_iterator);
Date toDate(const std::string &);
//Stupid funs
void EditStation(std::list<Station>::iterator, int, int, double, double);
bool addStationInfo(std::list<Station> &, const std::string &);
std::list<Station>::iterator findStation(std::list<Station> &, const std::string &);
std::list<Station>::iterator addStationData(std::list<Station> &, const std::string &);
std::list<Station>::iterator checkId(std::list<Station> &, const std::string &);