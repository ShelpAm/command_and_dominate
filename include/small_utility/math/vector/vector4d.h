#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_

#include "small_utility/math/vector/vector4d_forward.h"

#include <cassert>
#include <cstdio>

template<typename value_type> struct Vector4D {
 public:
  Vector4D(value_type _x, value_type _y, value_type _z, value_type _w);
  value_type &operator[](int index) {
    if (index < 0 || index > 3) {
      printf("[ERROR::Vector4d<value_type>::operator[]] "
             "index is out of range.");
    }
    assert(index >= 0 && index < 4);
    return *(reinterpret_cast<value_type *>(this) + index);
  }
  ~Vector4D();

  value_type x, y, z, w;
};

#include "small_utility/math/vector/vector4d.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_
