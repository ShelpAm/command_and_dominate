#ifndef COMMAND_AND_DOMINATE_SRC_MATH_COLOR_COLOR_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_COLOR_COLOR_H_

#include "small_utility/math/color/color_forward.h"

class Color {
 public:
  static Color Create(
      float const r, float const g, float const b, float const a = 1.0f);
  Color(float r, float g, float b, float a);
  Color &operator=(Color const &rhs);
  Color() = delete;
  bool operator==(Color const &rhs);
  bool operator!=(Color const &rhs);

  float const GetR() const { return r_; }
  float const GetG() const { return g_; }
  float const GetB() const { return b_; }
  float const GetA() const { return a_; }
  void SetR(float const rhs) { r_ = rhs; }
  void SetG(float const rhs) { g_ = rhs; }
  void SetB(float const rhs) { b_ = rhs; }
  void SetA(float const rhs) { a_ = rhs; }

 private:
  float r_, g_, b_, a_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_COLOR_COLOR_H_
