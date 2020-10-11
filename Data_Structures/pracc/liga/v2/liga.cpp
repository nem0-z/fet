#include "liga.hpp"

#include <iostream>

void Solution::Date::print() const {
  std::cout << day << "-" << month << "-" << year << std::endl;
}

void Solution::Match::print() const {
  using std::cout;
  using std::endl;
  cout << "\t\t MATCH INFO" << endl;
  cout << "Home team: " << home->name << endl;
  cout << "Away team: " << away->name << endl;
  cout << "Head referee: " << mainRef->name << " " << mainRef->surname << endl;
  cout << "Assistant referee: " << assistantRef->name << " "
       << assistantRef->surname << endl;
  cout << "Date: ";
  date.print();
  cout << "Played: " << (played ? "Yes" : "No") << endl;
  if (played) cout << "Result: " << result << endl;
  if (revert) cout << "NOTE: THIS MATCH WAS REVERTED!" << endl;
  cout << endl;
}

void Solution::Schedule::addMatch(const Match &match) {
  allMatches.emplace_back(match);
}

void Solution::Schedule::playMatch(const Match &match) {
  ++unplayedMatches_;
  playedMatches_ = unplayedMatches_ - 1;
}

bool Solution::Schedule::matchAvailable() const {
  if (unplayedMatches_ == -1 || unplayedMatches_ > allMatches.size() - 1) {
    std::cout << "No scheduled matches to play!" << std::endl;
    return false;
  }
  return true;
}

void Solution::Schedule::annul() {
  allMatches[playedMatches_].revert = true;
  --playedMatches_;
  while (true) {
    if (!allMatches[playedMatches_].revert) break;
    --playedMatches_;
  }
}

void Solution::Date::getDate() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  year = 1900 + ltm->tm_year;
  month = 1 + ltm->tm_mon;
  day = ltm->tm_mday;
}

void Solution::Date::updateDate() {
  day += 7;
  if (day >= 28) {
    ++month;
    day = 1;
    if (month >= 12) {
      month = 1;
      ++year;
    }
  }
}

int Solution::retardInput() const {
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << "Wrong input!" << std::endl;
  return -1;
}

int Solution::printMenu() const {
  using std::cin;
  using std::cout;
  using std::endl;
  int choice = -1;
  cout << "\n1. Add new team" << endl;
  cout << "2. Add new referee" << endl;
  cout << "3. Add new league" << endl;
  cout << "4. Play the match" << endl;
  cout << "5. Annul last played match" << endl;
  cout << "6. Show team info" << endl;
  cout << "7. Show league table" << endl;
  cout << "8. Show all matches" << endl;
  cout << "9. Exit" << endl;
  cout << "Your choice: ";
  return (cin >> choice ? choice : retardInput());
}

void Solution::choice(int userChoice) {
  if (userChoice != -1 || userChoice != 9) {
    if (userChoice == 1)
      addTeam();
    else if (userChoice == 2)
      addReferee();
    else if (userChoice == 3)
      addLeague();
    else if (userChoice == 4)
      playMatch();
    else if (userChoice == 5)
      annulMatch();
    else if (userChoice == 6)
      teamInfo();
    else if (userChoice == 7)
      leagueInfo();
    else if (userChoice == 8)
      matchesInfo();
  }
}

int Solution::randomRef(const std::string &country) {
  return rand() % referees_[country].size();
}

void Solution::updateRef(int &ref1, int &ref2, const std::string &country) {
  if (ref1 == referees_[country].size() - 1)
    ref2 = ref1 - 1;
  else
    ref2 = ref1 + 1;
}

std::pair<int, int> Solution::pickRefs(const std::string &country) {
  std::pair<int, int> refs;
  int ref1 = randomRef(country);
  int ref2 = randomRef(country);
  if (ref1 == ref2) updateRef(ref1, ref2, country);
  refs.first = ref1;
  refs.second = ref2;
  return refs;
}

std::unordered_map<std::string, Solution::League>::iterator
Solution::getLeague() {
  using std::cin;
  using std::cout;
  using std::endl;
  std::string country;
  std::string leagueName;
  cout << "Country: ";
  cin >> country;
  auto findCountry = leagues_.find(country);
  if (findCountry == leagues_.end())
    throw std::runtime_error("No leagues in this country!\n");
  cout << "League name: ";
  cin >> leagueName;
  auto league = findCountry->second.find(leagueName);
  if (league == findCountry->second.end())
    throw std::runtime_error("That league doesn't exist!\n");
  return league;
}

std::unordered_map<std::string, Solution::Team>::const_iterator
Solution::getTeam() const {
  using std::cin;
  using std::cout;
  using std::endl;
  std::string country;
  std::string teamName;
  cout << "Country: ";
  cin >> country;
  auto getCountry = teams_.find(country);
  if (getCountry == teams_.end())
    throw std::runtime_error("No teams found in that country!\n");
  cout << "Team name: ";
  cin >> teamName;
  auto team = getCountry->second.find(teamName);
  if (team == getCountry->second.end())
    throw std::runtime_error("No team found with that name!\n");
  return team;
}

bool Solution::enoughRefs(const std::string &country) {
  auto refs = referees_.find(country);
  if (refs == referees_.end() || refs->second.size() < 2) return false;
  return true;
}

bool Solution::enoughTeams(const std::string &country) {
  if (teams_.find(country) == teams_.end() || teams_[country].size() < 2)
    return false;
  return true;
}

void Solution::addTeam() {
  using std::cin;
  using std::cout;
  using std::endl;
  Team team;
  cout << "Team name: ";
  cin >> team.name;
  cout << "Country: ";
  cin >> team.country;
  cout << "City: ";
  cin >> team.city;
  cout << "Stadium: ";
  cin >> team.stadium;

  auto success = teams_[team.country].emplace(team.name, std::move(team));
  cout << (success.second ? "Team added!" : "Can't add this team!") << endl;
}
void Solution::addReferee() {
  using std::cin;
  using std::cout;
  using std::endl;
  Referee ref;
  cout << "Referee name: ";
  cin >> ref.name;
  cout << "Referee surname: ";
  cin >> ref.surname;
  cout << "Country: ";
  cin >> ref.country;

  // seek for same entry
  // O(n) but adding new referee will be less frequent compared to
  // random access to referees we need when generating schedule
  auto existingRef = std::find_if(
      referees_[ref.country].begin(), referees_[ref.country].end(),
      [&](const Referee &other) {
        return ref.name == other.name && ref.surname == other.surname;
      });
  if (existingRef == referees_[ref.country].end()) {
    referees_[ref.country].emplace_back(std::move(ref));
    cout << "Referee added!" << endl;
  } else {
    cout << "Can't add this referee!" << endl;
  }
}
void Solution::addLeague() {
  using std::cin;
  using std::cout;
  using std::endl;
  League league;
  cout << "League name: ";
  cin >> league.name;
  cout << "Country: ";
  cin >> league.country;

  if (!enoughTeams(league.country) || !enoughRefs(league.country)) {
    cout << "Not enough data for forming a league!" << endl;
    return;
  }

  league.teams = &teams_[league.country];
  auto &refs = referees_.find(league.country)->second;

  // deal with date stuff
  Date date;
  date.getDate();

  // generate schedule
  for (auto &t1 : *league.teams) {
    Team *const home = &t1.second;
    for (auto &t2 : *league.teams) {
      Team *const away = &t2.second;

      if (home->name == away->name) continue;

      Match newMatch;
      // set opponents
      newMatch.home = home;
      newMatch.away = away;

      // deal more with date stuff
      date.updateDate();
      newMatch.date = date;

      // pick referees randomly
      std::pair<int, int> refIndex = pickRefs(league.country);
      newMatch.mainRef = &refs[refIndex.first];
      newMatch.assistantRef = &refs[refIndex.second];

      // update match tables for every team and league
      home->matches.addMatch(newMatch);
      away->matches.addMatch(newMatch);
      league.matches.addMatch(std::move(newMatch));
    }
  }
  auto success =
      leagues_[league.country].emplace(league.name, std::move(league));
  cout << (success.second ? "League added!" : "Can't add this league!") << endl;
}

void Solution::playMatch() {
  using std::cin;
  using std::cout;
  using std::endl;
  std::string result;
  try {
    auto league = getLeague();

    // fetch scheduled league match
    auto &leagueSched = league->second.matches;
    if (!leagueSched.matchAvailable()) return;
    Match &pendingMatch = leagueSched.allMatches[leagueSched.unplayedMatches_];

    const std::string homeTeamName = pendingMatch.home->name;
    const std::string awayTeamName = pendingMatch.away->name;

    // this is fine since those teams for sure exist if we reached this point
    auto getHome = league->second.teams->find(homeTeamName);
    auto getAway = league->second.teams->find(awayTeamName);

    Team &homeTeam = getHome->second;
    Team &awayTeam = getAway->second;

    // fetch scheduled match for each team
    Match &hMatch =
        homeTeam.matches.allMatches[homeTeam.matches.unplayedMatches_];
    Match &aMatch =
        awayTeam.matches.allMatches[awayTeam.matches.unplayedMatches_];

    pendingMatch.print();
    cout << "Enter result in form: home-away, e.g. 3-1" << endl;
    cin >> result;
    if (!std::isdigit(result[0]) || !std::isdigit(result[2]) ||
        result.size() > 3 || result[1] != '-') {
      cout << "Wrong input!" << endl;
      return;
    }

    // parse result
    const int homeGoals = result[0] - 48;
    const int awayGoals = result[2] - 48;
    if (homeGoals > awayGoals) {
      homeTeam.points += 3;
    } else if (homeGoals == awayGoals) {
      homeTeam.points += 1;
      awayTeam.points += 1;
    } else {
      awayTeam.points += 3;
    }

    hMatch.played = aMatch.played = pendingMatch.played = true;
    hMatch.result = aMatch.result = pendingMatch.result = result;

    // update league table and team table
    hMatch.home->matches.playMatch(pendingMatch);
    hMatch.away->matches.playMatch(pendingMatch);
    leagueSched.playMatch(std::move(pendingMatch));
  } catch (const std::runtime_error &err) {
    cout << err.what();
    return;
  }
}

void Solution::annulMatch() {
  using std::cin;
  using std::cout;
  using std::endl;
  try {
    // find league and last played match
    auto league = getLeague();
    if (league->second.matches.playedMatches_ == -1) {
      cout << "No played matches available!" << endl;
      return;
    }
    auto &leagueSched = league->second.matches;

    // fetch last played league match
    Match &lastMatch =
        league->second.matches.allMatches[leagueSched.playedMatches_];

    Team *const homeTeam = lastMatch.home;
    Team *const awayTeam = lastMatch.away;

    // fetch last played match for each team
    Match &hMatch =
        homeTeam->matches.allMatches[awayTeam->matches.playedMatches_];
    Match &aMatch =
        awayTeam->matches.allMatches[awayTeam->matches.playedMatches_];

    lastMatch.print();
    cout << "Reverting this match..." << endl;
    // parse result in reverse lol
    const std::string &result = lastMatch.result;
    const int homeGoals = result[0] - 48;
    const int awayGoals = result[2] - 48;
    if (homeGoals > awayGoals) {
      homeTeam->points -= 3;
    } else if (homeGoals == awayGoals) {
      homeTeam->points -= 1;
      awayTeam->points -= 1;
    } else {
      awayTeam->points -= 3;
    }
    if (homeTeam->points < 0) homeTeam->points = 0;
    if (awayTeam->points < 0) awayTeam->points = 0;

    // hMatch.revert = true;
    // aMatch.revert = true;
    // lastMatch.revert = true;

    league->second.matches.annul();
    homeTeam->matches.annul();
    awayTeam->matches.annul();
  } catch (const std::runtime_error &err) {
    cout << err.what();
    return;
  }
}
void Solution::teamInfo() const {
  using std::cin;
  using std::cout;
  using std::endl;
  try {
    auto team = getTeam();
    cout << "\nName: " << team->second.name << endl;
    cout << "Country: " << team->second.country << endl;
    cout << "City: " << team->second.city << endl;
    cout << "Stadium: " << team->second.stadium << endl;
    cout << "Points: " << team->second.points << endl;
    if (team->second.matches.allMatches.empty())
      cout << "No scheduled matches!" << endl;
    else
      for (const auto &m : team->second.matches.allMatches) m.print();
  } catch (const std::runtime_error &err) {
    cout << err.what();
    return;
  }
}
void Solution::leagueInfo() {
  using std::cin;
  using std::cout;
  using std::endl;
  try {
    auto league = getLeague();
    cout << "\t\t\tTeam\t\t\tPoints\n" << endl;
    cout << std::string(70, '-') << endl;
    for (const auto &team : *league->second.teams) {
      cout << "\t\t\t" << team.second.name << "\t\t\t" << team.second.points
           << endl;
    }
  } catch (const std::runtime_error &err) {
    cout << err.what();
    return;
  }
}
void Solution::matchesInfo() const {
  using std::cout;
  using std::endl;
  if (!leagues_.empty()) {
    for (const auto &l : leagues_) {
      for (const auto &league : l.second) {
        cout << "League: " << league.second.name << endl;
        cout << "Country: " << league.second.country << endl;
        cout << "\t\tMATCHES" << endl;
        for (const auto &m : league.second.matches.allMatches) m.print();
      }
    }
  } else {
    cout << "No scheduled matches" << endl;
  }
}

void Solution::solve() {
  while (true) {
    int userChoice = printMenu();
    choice(userChoice);
    if (userChoice == 9) break;
  }
}
