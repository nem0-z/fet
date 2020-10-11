#include <string>
#include <cmath>
#include "Degree.hpp"
#include "Radian.hpp"
#include "Consts.hpp"
#include "Cplx.hpp"

namespace vjezbe10 {
  
  std::string Cplx::toString() const{
    return std::to_string(re_) + " + i" + std::to_string(im_);
  }

  double Cplx::modulus() const{
    return sqrt((re_*re_)+(im_*im_));
  }

  Radian Cplx::angle() const{
    return Radian{atan(im_/re_)};
  }

  Cplx::Cplx(double mod, Radian angRad){
    re_ = mod*angRad.sinus();
    im_ = mod*angRad.cosinus();
  }
  
  Cplx::Cplx(double mod, Degree angDeg){
    re_ = mod*angDeg.sinus()*PI/180;
    im_ = mod*angDeg.cosinus()*PI/180;
  }

  Cplx Cplx::add(const Cplx& other) const{
    return Cplx{re_ + other.re_ , im_ + other.im_};
  }

  Cplx& Cplx::append(const Cplx& other){
    re_+=other.re_;
    im_+=other.im_;
    return *this;
  }
   Cplx Cplx::makeNegative() const{
      return Cplx{-re_, -im_};
   }
  
}
