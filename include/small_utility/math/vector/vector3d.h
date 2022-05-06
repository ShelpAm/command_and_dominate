#ifndef COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_
#define COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_

#include <memory>

#include "small_utility/math/vector/vector3d_forward.h"

template<typename value_type> struct Vector3D {
 public:
  Vector3D();
  Vector3D(value_type scalar);
  Vector3D(value_type _x, value_type _y, value_type _z);
  Vector3D(Vector3D<value_type> const &rhs);
  ~Vector3D();

  value_type x, y, z;
};

template<typename value_type> void operator+=(
    Vector3D<value_type> &lhs, value_type rhs) {
  lhs.x += rhs;
  lhs.y += rhs;
  lhs.z += rhs;
}

template<typename value_type> void operator+=(
    Vector3D<value_type> &lhs, Vector3D<value_type> const &rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  lhs.z += rhs.z;
}

template<typename value_type> Vector3D<value_type> operator/(
    Vector3D<value_type> const &lhs, value_type rhs) {
  return Vector3D<value_type>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template<typename value_type> Vector3D<value_type> operator*(
    Vector3D<value_type> const &lhs, value_type rhs) {
  return Vector3D<value_type>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

#include "small_utility/math/vector/vector3d.hpp"

#endif // !COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_
