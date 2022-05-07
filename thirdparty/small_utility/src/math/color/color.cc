#include "small_utility/math/color/color.h"

Color Color::Create(
    float const r, float const g, float const b, float const a) {
  return Color(r, g, b, a);
}

Color::Color(float const r, float const g, float const b, float const a)
    : r_(r), g_(g), b_(b), a_(a) {}

Color &Color::operator=(Color const &rhs) {
  r_ = rhs.GetR();
  g_ = rhs.GetG();
  b_ = rhs.GetB();
  a_ = rhs.GetA();
  return *this;
}

bool Color::operator==(Color const &rhs) {
  return r_ == rhs.GetR() && g_ == rhs.GetG() && b_ == rhs.GetB() &&
               a_ == rhs.GetA();
}

bool Color::operator!=(Color const &rhs) {
  return !(*this == rhs);
}
