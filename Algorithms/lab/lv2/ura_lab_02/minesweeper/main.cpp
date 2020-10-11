#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& elements, int element) {
  // TODO make it unique, use std::find
  auto it = std::find(elements.begin(),elements.end(),element);
  if(it == elements.end()){
  elements.push_back(element);
  return true;
  }
  return false;
}

class Field {
  private:
  int val_ = 0;
  bool covered_ = true;

  public:
  void uncover() { covered_ = false; }
  bool is_bomb() const { return val_ >= 100; }
  void increment() { val_ += 1; }
  bool covered() const { return covered_; }
  void set_bomb() { val_ = 100; }
  int value() const { return val_; }

  friend std::ostream& operator<<(std::ostream& out, const Field& f);
};

std::ostream& operator<<(std::ostream& out, const Field& f) {
  if (f.covered()) {
    return out << " ▣";
  }
  if (f.val_ >= 100) {
    return out << " ☀";
  }
  switch (f.val_) {
    case 0:
      out << " ◻";
      break;
    case 1:
      out << " ①";
      break;
    case 2:
      out << " ②";
      break;
    case 3:
      out << " ③";
      break;
    case 4:
      out << " ④";
      break;
    case 5:
      out << " ⑤";
      break;
    case 6:
      out << " ⑥";
      break;
    case 7:
      out << " ⑦";
      break;
    case 8:
      out << " ⑧";
      break;
  }
  return out;
}

class Playground {
  private:
  std::vector<std::vector<Field>> terrain_;

  void place_bomb(int bomb_x, int bomb_y) {
    terrain_[bomb_x][bomb_y].set_bomb();
    if (bomb_x > 0 && bomb_y > 0) terrain_[bomb_x - 1][bomb_y - 1].increment();
    if (bomb_x < 9 && bomb_y < 9) terrain_[bomb_x + 1][bomb_y + 1].increment();
    if (bomb_x > 0 && bomb_y < 9) terrain_[bomb_x - 1][bomb_y + 1].increment();
    if (bomb_x < 9 && bomb_y > 0) terrain_[bomb_x + 1][bomb_y - 1].increment();
    if (bomb_x > 0) terrain_[bomb_x - 1][bomb_y].increment();
    if (bomb_x < 9) terrain_[bomb_x + 1][bomb_y].increment();
    if (bomb_y < 9) terrain_[bomb_x][bomb_y + 1].increment();
    if (bomb_y > 0) terrain_[bomb_x][bomb_y - 1].increment();
  }

  public:
  Playground() {
    terrain_.resize(10);
    for (auto& row : terrain_) {
      row.resize(10);
    }
    // set bombs randomly
    std::vector<int> bombs;
    while (bombs.size() < 10) {
      push_unique(bombs, rand() % 100);
    }
    for (const auto& bomb : bombs) {
      place_bomb(bomb / 10, bomb % 10);
    }
  }

  bool open_field(int x, int y) {
    if (x >= 10 || y >= 10 || x < 0 || y < 0) return false;
    auto& f = terrain_[x][y];
    if (!f.covered()) return false;
    f.uncover();
    if (f.is_bomb()) {
      return true;
    }
    if (f.value() == 0) {
      // TODO if val_ is zero, uncover all neighboring zero fields.
      open_field(x + 1, y);
      open_field(x, y + 1);
      open_field(x - 1, y);
      open_field(x, y - 1);
    }
    return false;
  }

  friend std::ostream& operator<<(std::ostream& out,
                                  const Playground& playground);
};

std::ostream& operator<<(std::ostream& out, const Playground& playground) {
  out << "______________________" << std::endl;
  for (const auto& row : playground.terrain_) {
    out << "|";
    for (const auto& column : row) {
      out << column;
    }
    out << '|' << std::endl;
  }
  out << "______________________" << std::endl;
  return out;
}

int main() {
  srand(clock());

  Playground playground;
  std::cout << playground << std::endl;

  int x;
  int y;
  while (std::cin >> x >> y) {
    std::cout << "Opening " << x << ", " << y << std::endl;
    bool hit_a_bomb = playground.open_field(x, y);
    std::cout << playground << std::endl;
    if (hit_a_bomb) {
      std::cout << "You loose!" << std::endl;
      break;
    }
  }
}
