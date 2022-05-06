#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_

#include "small_utility/math/matrix/matrix4x4_forward.h"

#include <cassert>
#include <cstdio>

#include "small_utility/math/vector/vector4d.h"

template<typename value_type> struct Matrix4x4 {
 public:
  using row_type = Vector4D<value_type>;

  Matrix4x4(value_type scalar);
  Matrix4x4(value_type x0, value_type y0, value_type z0, value_type w0,
            value_type x1, value_type y1, value_type z1, value_type w1,
            value_type x2, value_type y2, value_type z2, value_type w2,
            value_type x3, value_type y3, value_type z3, value_type w3);
  row_type &operator[](int index) {
    if (index < 0 || index > 3) {
      printf("[ERROR::Matrix4x4<value_type>::operator[]] "
             "index is out of range.");
    }
    assert(index >= 0 && index < 4);
    return value[index];
  }
  ~Matrix4x4();

  row_type value[4];
};

template<typename value_type> Matrix4x4<value_type> Perspective(
    value_type y_field_of_view, value_type aspect,
    value_type z_near, value_type z_far);

#include "small_utility/math/matrix/matrix4x4.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
