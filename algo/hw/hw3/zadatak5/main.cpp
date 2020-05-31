#include <iostream>
#include <vector>
#include <limits.h>

#define N 8

int ploca[N][N];
const int limit = N * N; // board limits

void put(int x, int y, int n) { ploca[x][y] = n; }
void erase(int x, int y) { ploca[x][y] = 0; }
bool free(int x, int y)
{
  return (ploca[x][y] == 0 && x >= 0 && y >= 0 && x < 8 && y < 8);
}

int chess(int x, int y, int n)
{
  if (n == limit) // jumped on last free place
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        std::cout << ploca[j][i] << '\t';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return INT_MAX;
  }
  int res = -1;
  if (res == -1 && free(x + 2, y + 1))
  {
    put(x + 2, y + 1, n + 1);
    res = chess(x + 2, y + 1, n + 1);
    if (res == -1)
    {
      erase(x + 2, y + 1);
    }
  }
  if (res == -1 && free(x + 1, y + 2))
  {
    put(x + 1, y + 2, n + 1);
    res = chess(x + 1, y + 2, n + 1);
    if (res == -1)
    {
      erase(x + 1, y + 2);
    }
  }
  if (res == -1 && free(x - 1, y + 2))
  {
    put(x - 1, y + 2, n + 1);
    res = chess(x - 1, y + 2, n + 1);
    if (res == -1)
    {
      erase(x - 1, y + 2);
    }
  }
  if (res == -1 && free(x - 2, y + 1))
  {
    put(x - 2, y + 1, n + 1);
    res = chess(x - 2, y + 1, n + 1);
    if (res == -1)
    {
      erase(x - 2, y + 1);
    }
  }
  if (res == -1 && free(x - 2, y - 1))
  {
    put(x - 2, y - 1, n + 1);
    res = chess(x - 2, y - 1, n + 1);
    if (res == -1)
    {
      erase(x - 2, y - 1);
    }
  }
  if (res == -1 && free(x - 1, y - 2))
  {
    put(x - 1, y - 2, n + 1);
    res = chess(x - 1, y - 2, n + 1);
    if (res == -1)
    {
      erase(x - 1, y - 2);
    }
  }
  if (res == -1 && free(x + 1, y - 2))
  {
    put(x + 1, y - 2, n + 1);
    res = chess(x + 1, y - 2, n + 1);
    if (res == -1)
    {
      erase(x + 1, y - 2);
    }
  }
  if (res == -1 && free(x + 2, y - 1))
  {
    put(x + 2, y - 1, n + 1);
    res = chess(x + 2, y - 1, n + 1);
    if (res == -1)
    {
      erase(x + 2, y - 1);
    }
  }
  return res;
}

int main(void)
{
  ploca[0][0] = 1;
  chess(0, 0, 1);
  return 0;
}
