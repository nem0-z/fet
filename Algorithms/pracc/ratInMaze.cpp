#include <iostream>

int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
int solution[4][4] = {0};

void print() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << solution[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool safe(int x, int y) {
  return x < 4 && y < 4 && x >= 0 && y >= 0 && maze[x][y] == 1;
}

void solveMaze(int x, int y) {
  if (solution[4 - 1][4 - 1] == 1) {
    print();
    return;
  }
  if (safe(x, y)) {
    solution[x][y] = 1;
    solveMaze(x, y + 1);
    solveMaze(x + 1, y);
    solution[x][y] = 0;
  } else
    return;
}

int main(int argc, char *argv[]) {
  solveMaze(0, 0);
  return 0;
}
