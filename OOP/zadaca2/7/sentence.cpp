#include <iostream>
#include <map>
#include <string>
using std::cin;
using std::getline;
using std::string;

int main(void) {
  std::map<char, int> repeat;
  string a;
  getline(cin, a);
  for (auto i = 0; i < a.size(); ++i) {
    for (auto x = 0; x < a.size(); ++x) {
            if (a[i] == a[x]) {
        repeat[a[i]]++;
      }
    }
  }
  for (auto it = repeat.begin(); it != repeat.end(); ++it)
    std::cout << "Letter \'" << it->first << "\' shows up " << it->second
              << " times!" << std::endl;
  return 0;
}
