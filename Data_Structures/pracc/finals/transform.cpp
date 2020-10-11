#include <iostream>
#include <queue>
#include <stack>
#include <string>

void transform(const std::string& input) {
  std::stack<char> s1, s3, s4;
  std::queue<char> q2;
  for (auto c : input) {
    if (std::isalpha(c)) {
      // c = std::toupper(c);
      s1.push(c);
    } else if (c == '+') {
      q2.push(s1.top());
      s1.pop();
    } else if (c == '=') {
      s3.push(q2.front());
      q2.pop();
    } else if (c == '-') {
      s4.push(s3.top());
      s3.pop();
    } else if (c == '>') {
      std::cout << s4.top();
      s4.pop();
    } else
      continue;
  }
}
int main(int argc, char *argv[])
{
  std::string s = "aBcD+++..e==*-+>F^-+(())==+=-%#-->>>=>";
  transform(s);
  return 0;
}
