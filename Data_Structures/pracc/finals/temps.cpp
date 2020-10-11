#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

struct AvgTempinterface {
  virtual void add(int year, int month, int day, float temp) = 0;
  virtual void load(std::istream&) = 0;
  virtual std::pair<bool, float> get_temp(int month, int day) = 0;
  virtual std::pair<bool, float> get_temp(int month) = 0;
};

class AverageTemp : public AvgTempinterface {
  private:
  class Day {
public:
    int dayNr;
    std::vector<float> temps;
    float avgTemp;
    void updateTemp() {
      float sum = 0.;
      for (auto t : temps) sum += t;
      avgTemp = sum / temps.size();
    }
  };
  class Month {
public:
    int monthNr;
    std::vector<Day> days;
    float avgTemp;
    void updateTemp() {
      float sum = 0.;
      for (auto d : days) sum += d.avgTemp;
      avgTemp = sum / days.size();
    }
  };
  std::unordered_map<int, std::vector<Month>> years_;

  public:
  void add(int year, int month, int day, float temp) {
    auto& currentYear = years_[year];
    currentYear.resize(12);
    auto& currentMonth = currentYear[month];
    currentMonth.days[day].temps.emplace_back(temp);
    currentMonth.days[day].updateTemp();
  }
  void load(std::istream& in) {
    int year, month, day;
    float temp;
    while (in >> year >> month >> day >> temp) add(year, month, day, temp);
  }
  std::pair<bool, float> get_temp(int month, int day) {
    return std::pair<bool, float>(0, 0);
  }
  std::pair<bool, float> get_temp(int month) {
    float sum = 0;
    for (auto year : years_) {
      auto& currentMonth = year.second[month];
      if (currentMonth.days.empty()) continue;
      sum += currentMonth.avgTemp;
    }
    return std::make_pair(true, sum / years_.size());
  }
};

int main(int argc, char* argv[]) {
  AverageTemp app;
  app.add(2015, 11, 20, 4.56);
  // app.add(2014, 11, 20, 5.56);
  // app.add(2013, 11, 20, 3.56);
  // auto x = app.get_temp(11);
  // std::cout << x.second << std::endl;
  return 0;
}
