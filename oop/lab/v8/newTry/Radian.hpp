#pragma once

#include <cmath>

namespace vjezbe10 {

class Radian {
  public:
  explicit Radian(double value) : value_{value} {}

  double getValue() const { return value_; }

  void setValue(double value) { value_ = value; }

  double sinus() const { return sin(value_); }

  double cosinus() const { return cos(value_); }

  private:
  double value_;
};

}  // namespace vjezbe10

