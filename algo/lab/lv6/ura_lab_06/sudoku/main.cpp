#include <chrono>
#include <iostream>
#include <thread>

// vratiti true ako mozemo na polje i,j postaviti b
bool check_valid(int sudoku[9][9], int i, int j, int b) {
  for (int a = 0; a < 9; a++) {
    if (sudoku[i][a] == b) return false;
    if (sudoku[a][j] == b) return false;
  }
  for (int c = i / 3; c < i / 3 + 3; c++) {
    for (int k = j / 3; k < j / 3 + 3; k++) {
      if (sudoku[c][k] == b) {
        return false;
      }
    }
  }
  return true;
}

bool finished(int sudoku[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (sudoku[i][j] == 0) return false;
    }
  }
  return true;
}

void print_sudoku(int sudoku[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cout << sudoku[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void solve_sudoku(int sudoku[9][9], int i, int j) {
  print_sudoku(sudoku);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  if (finished(sudoku)) {
    print_sudoku(sudoku);
  }

  while (sudoku[i][j] != 0) {
    i++;
    if (i >= 9) {
      i = 0;
      j++;
    }
    if (j == 9) {
      return;
    }
  }

  for (int b = 1; b <= 9; b++) {
    if (check_valid(sudoku, i, j, b)) {
      sudoku[i][j] = b;
      solve_sudoku(sudoku, i, j);
      sudoku[i][j] = 0;
    }
  }
}

int main() {
  int sudoku[9][9]{{0, 0, 3, 0, 2, 0, 6, 0, 0}, {9, 0, 0, 3, 0, 5, 0, 0, 1},
                   {0, 0, 1, 8, 0, 6, 4, 0, 0}, {0, 0, 8, 1, 0, 2, 9, 0, 0},
                   {7, 0, 0, 0, 0, 0, 0, 0, 8}, {0, 0, 6, 7, 0, 8, 2, 0, 0},
                   {0, 0, 2, 6, 0, 9, 5, 0, 0}, {8, 0, 0, 2, 0, 3, 0, 0, 9},
                   {0, 0, 5, 0, 1, 0, 3, 0, 0}};
  solve_sudoku(sudoku, 0, 0);
}
