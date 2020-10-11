#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>

#define N 8

int board[N][N];

// Modifikovati program da nade samo prvo rijesenje, i nakon toga da stane.

void place_queen(int x, int y) { board[x][y] = 1; }
void remove_queen(int x, int y) { board[x][y] = 0; }

bool is_free(int x, int y) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1) {
        // we found a queen placed on the board
        if (i == x) return false;
        if (j == y) return false;
        if ((i - x) == (j - y)) return false;
        if ((i - x) == -(j - y)) return false;
      }
    }
  }
  return true;
}

// Pretty print every step
void print_board() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (board[i][j] == 1)
        printf("\u265B ");
      else
        printf("o ");
    }
    putchar('\n');
  }
  putchar('\n');
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

// Main algo
bool nqueens(int column) {
  if (column == N) {
    print_board();
    return true;
  }
  for (int row = 0; row < N; row++) {
    if (is_free(row, column)) {
      place_queen(row, column);
      // debug
      // print_board();
      if (nqueens(column + 1)) {
        return true;
      };
      remove_queen(row, column);
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  nqueens(0);
  return 0;
}
