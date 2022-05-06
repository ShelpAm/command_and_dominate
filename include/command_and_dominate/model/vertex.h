#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_H_
#define COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_H_

#include "small_utility/math/vector/vector.h"
#include "command_and_dominate/model/vertex_forward.h"

template<typename value_type> struct Vertex {
 public:
  Vertex(Vector3D<value_type> _position, Vector3D<value_type> _normal,
      Vector3D<value_type> _texture_coordinate);
  ~Vertex();

  Vector3D<value_type> position;
  Vector3D<value_type> normal;
  Vector2D<value_type> texture_coordinate;
};

#include "command_and_dominate/model/vertex.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_H_
