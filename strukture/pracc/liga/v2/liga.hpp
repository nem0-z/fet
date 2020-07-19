#pragma once
#include <ctype.h>

#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
private:
  // class declarations
  class Team;
  class Referee;
  class Match;
  class League;
  class Date;
  class Schedule;

  // class definitions
  class Date
  {
  public:
    void getDate();
    void updateDate();
    void print() const;

  private:
    int day;
    int month;
    int year;
  };
  class Schedule
  {
  public:
    std::vector<Match> allMatches;
    int unplayedMatches_ = 0;
    int playedMatches_ = -1;
    void addMatch(const Match &);
    void playMatch(const Match &);
    void annul();
    bool matchAvailable() const;
  };
  class Team
  {
  public:
    std::string name = "N/A";
    std::string country = "N/A";
    std::string city = "N/A";
    std::string stadium = "N/A";
    int points = 0;
    Schedule matches;
  };
  class Referee
  {
  public:
    std::string name = "N/A";
    std::string surname = "N/A";
    std::string country = "N/A";
  };
  class Match
  {
  public:
    Team *home;
    Team *away;
    Referee *mainRef;
    Referee *assistantRef;
    Date date;
    std::string result = "N/A";
    bool played = false;
    bool revert = false;
    void print() const;
  };
  class League
  {
  public:
    std::string name = "N/A";
    std::string country = "N/A";
    std::unordered_map<std::string, Team> *teams;
    Schedule matches;
  };

  using leagueTable =
      std::unordered_map<std::string, std::unordered_map<std::string, League>>;
  using teamTable =
      std::unordered_map<std::string, std::unordered_map<std::string, Team>>;
  using refTable = std::unordered_map<std::string, std::vector<Referee>>;

  leagueTable leagues_;
  teamTable teams_;
  refTable referees_;

  // stupid stuff
  int retardInput() const;
  int printMenu() const;
  void choice(int);

  // not that stupid stuff
  int randomRef(const std::string &);
  void updateRef(int &, int &, const std::string &);
  std::pair<int, int> pickRefs(const std::string &);

  std::unordered_map<std::string, League>::iterator getLeague();
  std::unordered_map<std::string, Team>::const_iterator getTeam() const;

  bool enoughRefs(const std::string &);
  bool enoughTeams(const std::string &);

  // menu choices
  void addTeam();
  void addReferee();
  void addLeague();
  void playMatch();
  void annulMatch();
  void teamInfo() const;
  void leagueInfo();
  void matchesInfo() const;

public:
  void solve();
};
