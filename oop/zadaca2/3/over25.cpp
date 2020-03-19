#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void over25chars(const std::vector<std::string>& cont)
{
  for(auto i=0;i<cont.size();++i)
  {
    if((cont[i]).size()>=25) 
      std::cout << cont[i] << std::endl;
  }
}
int main(void) {
  std::ifstream dictionaryFile("words.txt");
  std::vector<std::string> dictionary;
  std::string word;
  while (dictionaryFile >> word) dictionary.push_back(std::move(word));
  over25chars(dictionary);
  return 0;
}

// exec time depending on type of argument:
// vector<string> 0.136s
// const vector<string> 0.117s
// const vector<string>& 0.111s
