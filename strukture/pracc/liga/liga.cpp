#include "liga.hpp"

#include <iostream>

void Solution::Date::print() const {
  std::cout << day << "-" << month << "-" << year << std::endl;
}
void Solution::Match::print() const {
  std::cout << "Home team: " << home->name << std::endl;
  std::cout << "Away team: " << away->name << std::endl;
  std::cout << "Head referee: " << mainRef->name << " " << mainRef->surname
            << std::endl;
  std::cout << "Assistant referee: " << assistantRef->name << " "
            << assistantRef->surname << std::endl;
  std::cout << "Date: ";
  date.print();
  std::cout << "Played: " << (played ? "Yes\n" : "No\n") << std::endl;
  if (played) std::cout << "Result: " << result << std::endl;
}
void Solution::MatchesDB::addMatch(const Match &match) {
  unplayedMatches.push(match);
  allMatches.emplace_back(std::move(match));
}
void Solution::MatchesDB::playMatch(const Match &match) {
  playedMatches.push(match);
  allMatches.emplace_back(std::move(match));
  unplayedMatches.pop();
  allMatches.pop_front();
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

Solution::Date Solution::date() {
  Date d;
  time_t now = time(0);
  tm *ltm = localtime(&now);
  d.year = 1900 + ltm->tm_year;
  d.month = 1 + ltm->tm_mon;
  d.day = ltm->tm_mday;
  return d;
}

void Solution::updateDate(int &day, int &month, int &year) {
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

int Solution::randomRef(const std::string &country) {
  return rand() % referees_[country].size();
}

void Solution::updateRef(int &ref1, int &ref2) {
  if (ref1 == referees_.size() - 1)
    ref2 = ref1 - 1;
  else
    ref2 = ref1 + 1;
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

  auto success = teams_[team.country].insert({team.name, std::move(team)});
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
  if (teams_.find(league.country) == teams_.end() ||
      teams_[league.country].size() < 2) {
    cout << "There have to be atleast 2 available teams in the country!"
         << endl;
    return;
  }
  auto refs = referees_.find(league.country);
  if (refs == referees_.end() || refs->second.size() < 2) {
    cout << "There have to be atleast 2 available referees in the country!"
         << endl;
    return;
  }
  league.teams = &teams_[league.country];

  // deal with date stuff
  Date currentDate = date();
  int year = currentDate.year;
  int month = currentDate.month;
  int day = currentDate.day;

  // generate schedule
  for (auto &t1 : *league.teams) {
    Team *home = &t1.second;
    for (auto &t2 : *league.teams) {
      Team *away = &t2.second;

      if (home->name == away->name) continue;

      Match newMatch;
      // set opponents
      newMatch.home = home;
      newMatch.away = away;

      // deal more with date stuff
      updateDate(day, month, year);
      newMatch.date = Date{day, month, year};

      // pick referees randomly
      int ref1 = randomRef(league.country);
      int ref2 = randomRef(league.country);
      if (ref1 == ref2) updateRef(ref1, ref2);
      newMatch.mainRef = &refs->second[ref1];
      newMatch.assistantRef = &refs->second[ref2];

      // update match tables for every team and league
      league.matches.addMatch(newMatch);
      home->matches.addMatch(newMatch);
      away->matches.addMatch(newMatch);
    }
  }
  auto success =
      leagues_[league.country].insert({league.name, std::move(league)});
  cout << (success.second ? "League added!" : "Can't add this league!") << endl;
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
  auto findLeague = findCountry->second.find(leagueName);
  if (findLeague == findCountry->second.end())
    throw std::runtime_error("That league doesn't exist!\n");
  return findLeague;
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
void Solution::playMatch() {
  using std::cin;
  using std::cout;
  using std::endl;
  std::string result;
  try {
    auto findLeague = getLeague();

    // fetch next scheduled match in league table
    auto &leagueSched = findLeague->second.matches;
    if (leagueSched.unplayedMatches.empty()) {
      cout << "No scheduled matches to play!" << endl;
      return;
    }
    Match &pendingMatch = leagueSched.unplayedMatches.front();

    const std::string homeTeamName = pendingMatch.home->name;
    const std::string awayTeamName = pendingMatch.away->name;

    // this is fine since those teams for sure exist if we reached this point
    auto getHome = findLeague->second.teams->find(homeTeamName);
    auto getAway = findLeague->second.teams->find(awayTeamName);

    Team &homeTeam = getHome->second;
    Team &awayTeam = getAway->second;

    // fetch next scheduled match in team table
    Match &match = homeTeam.matches.unplayedMatches.front();

    cout << "\t\t MATCH INFO" << endl;
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

    match.played = pendingMatch.played = true;
    match.result = pendingMatch.result = result;

    // update league table and team table
    match.home->matches.playMatch(pendingMatch);
    match.away->matches.playMatch(pendingMatch);
    leagueSched.playMatch(pendingMatch);
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
    auto findLeague = getLeague();
    if (findLeague->second.matches.playedMatches.empty()) {
      cout << "No played matches available!" << endl;
      return;
    }
    Match &lastMatch = findLeague->second.matches.playedMatches.top();
    Team *homeTeam = lastMatch.home;
    Team *awayTeam = lastMatch.away;

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

    // results are reverted so remove it from played matches collection
    findLeague->second.matches.playedMatches.pop();
    homeTeam->matches.playedMatches.pop();
    awayTeam->matches.playedMatches.pop();
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
    cout << "\t\tMATCHES" << endl;
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
    auto findLeague = getLeague();
    cout << "\t\t\tTeam\t\t\tPoints\n" << endl;
    cout << std::string(80, '-') << endl;
    for (const auto &team : *findLeague->second.teams) {
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
