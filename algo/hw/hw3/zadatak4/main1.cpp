#include <iostream>
#include <vector>

void rollDice_impl(std::vector<int>& solution, int throwLimit, int sumLimit,
                   int currentSum, int currentThrow) {
  if (currentThrow == throwLimit) {
    for (int s : solution) std::cout << s << " ";
    std::cout << std::endl;
    return;
  }
  for (int i = 1; i <= 6; ++i) {
    if (currentSum + i < sumLimit) {
      solution[currentThrow] = i;
      rollDice_impl(solution, throwLimit, sumLimit, currentSum + i,
                    currentThrow + 1);
    } else
      return;
  }
}
void rollDice(int throwLimit, int sumLimit) {
  std::vector<int> solution;
  solution.resize(throwLimit);
  rollDice_impl(solution, throwLimit, sumLimit, 0, 0);
}
int main(void) {
  rollDice(2, 5);
  return 0;
}
