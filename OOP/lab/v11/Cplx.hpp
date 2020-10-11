#pragma once
#include <iostream>
#include <string>

class Cplx {
  public:
  Cplx() = default;
  Cplx(const double re, const double im) : re_{re}, im_{im} {}

  void setReal(double re_) { this->re_ = re_; }
  void setImaginary(double im) { im_ = im; }
  int getReal() const { return re_; }
  int getImaginary() const {return im_; }
  std::string toString() const;

  Cplx operator+(int rhs) const;  // za izraz a+b, a ce biti this, a b je rhs
  // isto kao da smo rekli a.operator+(b);
  Cplx& operator+=(int rhs);

  private:
  double re_ = 0.;
  double im_ = 0.;
};

Cplx operator-(const Cplx& lhs, int rhs); //van klase smo, moras rec
// da uzima i lhs i rhs
Cplx& operator-=(Cplx& lhs, int rhs);
std::ostream& operator<<(std::ostream& out, const Cplx& rhs);
