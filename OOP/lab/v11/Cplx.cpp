#include "Cplx.hpp"
#include <cmath>

std::string Cplx::toString() const {
  return std::to_string(re_) + "+" + std::to_string(im_) + "i";
}

// double Cplx::modulus() const { return sqrt(pow(re_, 2) + pow(im_, 2)); }

std::ostream& operator<<(std::ostream& out, const Cplx& rhs){
  out<<rhs.getReal()<<" "<<rhs.getImaginary()<<std::endl;
  return out;
}

Cplx Cplx::operator+(int rhs) const
{
  Cplx foo( this->getReal() + rhs, this->getImaginary() + rhs );
  return foo;
}

Cplx& Cplx::operator+=(int rhs)
{
  this->setReal(this->getReal() + rhs);
  return *this;
}

Cplx operator-(const Cplx& lhs, int rhs)
{
  Cplx foo(lhs.getReal() - rhs, lhs.getImaginary() - rhs);
  return foo;
}

Cplx& operator-=(Cplx& lhs, int rhs)
{
  lhs.setReal(lhs.getReal() - rhs);
  return lhs;
  // lhs.setReal(lhs.getReal() - rhs).setImaginary(lhs.getImaginary() - rhs);
  // probaj ovo mora moc nesto vako samo negdje ti fulaju zagrade 
}



