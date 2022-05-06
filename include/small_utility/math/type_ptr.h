#ifndef COMMAND_AND_DOMINATE_SRC_MATH_TYPE_PTR_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_TYPE_PTR_H_

#include "small_utility/math/vector/vector.h"
#include "small_utility/math/matrix/matrix.h"

template<typename value_type> value_type *GetValuePtr(
    Vector2DPtr<value_type> vector2d_ptr);

template<typename value_type> value_type *GetValuePtr(
    Vector3DPtr<value_type> vector3d_ptr);

template<typename value_type> value_type *GetValuePtr(
    Vector4DPtr<value_type> vector4d_ptr);

template<typename value_type> value_type *GetValuePtr(
    Matrix4x4Ptr<value_type> matrix4x4_ptr);

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_TYPE_PTR_H_
