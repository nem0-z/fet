#include <algorithm>
#include <iostream>

int board[4][4];

bool free(int x, int y) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j] == 1) {
        if (i == x) return false;
        if (j == y) return false;
        if ((i - x) == (j - y)) return false;
        if ((i - x) == -(j - y)) return false;
      }
    }
  }
  return true;
}

void placequeen(int x, int y) { board[x][y] = 1; }

void removequeen(int x, int y) { board[x][y] = 0; }

void printBoard() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool nqueens(int col) {
  if (col == 4) {
    printBoard();
    return true;
  }
  for (int i = 0; i < 4; ++i) {
    if (free(i, col)) {
      placequeen(i, col);
      if (!nqueens(col + 1)) removequeen(i, col);
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  nqueens(0);
  return 0;
}
