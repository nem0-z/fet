#pragma once
#include <ctype.h>

#include <algorithm>
#include <cstddef>
#include <ctime>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
private:
  // struct declarations
  struct Team;
  struct Referee;
  struct Match;
  struct League;
  struct Date;
  struct MatchesDB;

  // struct definitions
  struct Date
  {
    int day;
    int month;
    int year;
  };
  struct MatchesDB
  {
    std::queue<Match> unplayedMatches;
    std::stack<Match> playedMatches;
    std::deque<Match> allMatches;
    void addMatch(const Match &);
    void playMatch(const Match &);
  };
  struct Team
  {
    std::string name = "N/A";
    std::string country = "N/A";
    std::string city = "N/A";
    std::string stadium = "N/A";
    int points = 0;
    MatchesDB matches;
  };
  struct Referee
  {
    std::string name = "N/A";
    std::string surname = "N/A";
    std::string country = "N/A";
  };
  struct Match
  {
    Team *home;
    Team *away;
    Referee *mainRef;
    Referee *assistantRef;
    Date date;
    std::string result = "N/A";
    bool played = false;
    void print() const;
  };
  struct League
  {
    std::string name = "N/A";
    std::string country = "N/A";
    std::unordered_map<std::string, Team> *teams;
    MatchesDB matches;
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

  // not so stupid stuff
  Date date();
  void updateDate(int &, int &, int &);
  void updateRef(int &, int &);
  int randomRef(const std::string &);
  std::unordered_map<std::string, League>::iterator getLeague();
  std::unordered_map<std::string, Team>::const_iterator getTeam() const;

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
  void start();
};
