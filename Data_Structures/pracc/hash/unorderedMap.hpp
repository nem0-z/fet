#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <list>
#include <vector>

template <typename Key, typename Value>
class hashTable {
  using pair = std::pair<Key, Value>;
  using bucket = std::list<pair>;

  public:
  hashTable() : size_{1000} { table_.resize(size_); }
  void insert(const pair& p) {
    Key key = p.first;
    size_t index = hash(key);
    auto myBucket = table_[index];
    auto it = std::find_if(myBucket.begin(), myBucket.end(),
                           [key](const pair& p) { return p.first == key; });
    if (it == myBucket.end())
      table_[index].emplace_back(p.second);
    else
      throw std::runtime_error("Key already exists!");
  }
  Value& operator[](const Key& k) {
    size_t index = hash(k);
    auto myBucket = table_[index];
    for (const auto& item : myBucket) std::cout << item.second << " ";
    std::cout << std::endl;
  }

  private:
  std::vector<bucket> table_;
  size_t size_;
  size_t hash(const int& k) { return ((k << 4) + k ^ 2) % size_; }
};
