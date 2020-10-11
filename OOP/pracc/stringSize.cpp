#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  size_t t = 0, maxSize = 0;
  std::vector<std::string> kontejner;
  std::string x, maxString;
  std::cout << "Unesi stringove: " << std::endl;
  while (std::cin >> x) {
    kontejner.push_back(x);
  }

  for (int k = 0; k < kontejner.size(); k++) {
    t = (kontejner[k]).size();
    if (t > maxSize) {
      maxSize = t;
      maxString = kontejner[k];
    }
  }
  std::cout << maxString << std::endl;
  return 0;
}
