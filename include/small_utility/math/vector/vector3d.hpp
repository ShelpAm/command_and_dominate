#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_

template<typename value_type> Vector3D<value_type>::Vector3D()
    : x(0.0f), y(0.0f), z(0.0f) {}

template<typename value_type> Vector3D<value_type>::Vector3D(
    value_type scalar) : x(scalar), y(scalar), z(scalar) {}

template<typename value_type> Vector3D<value_type>::Vector3D(
    value_type _x, value_type _y, value_type _z) : x(_x), y(_y), z(_z) {}

template<typename value_type> Vector3D<value_type>::Vector3D(
    Vector3D<value_type> const &rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

template<typename value_type> Vector3D<value_type>::~Vector3D() {}

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_
