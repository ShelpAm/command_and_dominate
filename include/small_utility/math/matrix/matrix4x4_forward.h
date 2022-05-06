#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_FORWARD_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_FORWARD_H_

#include <memory>

template<typename value_type> struct Matrix4x4;
template<typename value_type> using Matrix4x4Ptr =
    std::shared_ptr<Matrix4x4<value_type>>;

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_FORWARD_H_
