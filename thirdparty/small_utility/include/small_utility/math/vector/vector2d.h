#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR2D_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR2D_H_

#include "small_utility/math/vector/vector2d_forward.h"

template<typename value_type> struct Vector2D {
 public:
  Vector2D(value_type _x, value_type _y);
  ~Vector2D();

  value_type x, y;
};

#include "small_utility/math/vector/vector2d.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR2D_H_
