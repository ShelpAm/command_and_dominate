#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_

#include <cmath>

template<typename value_type> Matrix4x4<value_type>::Matrix4x4(
    value_type scalar)
    : value{row_type(scalar, 0, 0, 0),
            row_type(0, scalar, 0, 0),
            row_type(0, 0, scalar, 0),
            row_type(0, 0, 0, scalar)} {}

template<typename value_type> Matrix4x4<value_type>::Matrix4x4(
    value_type x0, value_type y0, value_type z0, value_type w0,
    value_type x1, value_type y1, value_type z1, value_type w1,
    value_type x2, value_type y2, value_type z2, value_type w2,
    value_type x3, value_type y3, value_type z3, value_type w3)
    : value{row_type(x0, y0, z0, w0),
            row_type(x1, y1, z1, w1),
            row_type(x2, y2, z2, w2),
            row_type(x3, y3, z3, w3)} {}

template<typename value_type> Matrix4x4<value_type>::~Matrix4x4() {}

template<typename value_type> Matrix4x4<value_type> Perspective(
    value_type y_field_of_view, value_type aspect,
    value_type z_near, value_type z_far) {
  value_type const tan_half_y_field_of_view =
      tan(y_field_of_view / static_cast<value_type>(2));

  Matrix4x4<value_type> result(static_cast<value_type>(0));
  result[0][0] =
      static_cast<value_type>(1) / (aspect * tan_half_y_field_of_view);
  result[1][1] = static_cast<value_type>(1) / tan_half_y_field_of_view;
  result[2][2] = - (z_far + z_near) / (z_far - z_near);
  result[2][3] = static_cast<value_type>(1);
  result[3][2] =
      - static_cast<value_type>(2) * z_far * z_near / (z_far - z_near);
  return result;
}

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_
