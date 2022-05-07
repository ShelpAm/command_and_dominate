#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_FORWARD_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_FORWARD_H_

#include <memory>

template<typename value_type> struct Vector4D;
template<typename value_type> using Vector4DPtr =
    std::shared_ptr<Vector4D<value_type>>;

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_FORWARD_H_
