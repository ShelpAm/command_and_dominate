#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR_4D_HPP_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR_4D_HPP_

template<typename value_type> Vector4D<value_type>::Vector4D(
    value_type _x, value_type _y, value_type _z, value_type _w)
    : x(_x), y(_y), z(_z), w(_w) {}

template<typename value_type> Vector4D<value_type>::~Vector4D() {}

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR_4D_HPP_
