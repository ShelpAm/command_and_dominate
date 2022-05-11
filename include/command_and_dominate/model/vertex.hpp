#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_HPP_
#define COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_HPP_

template<typename value_type>
Vertex<value_type>::Vertex() : position(), normal(), texture_coordinate() {}

template<typename value_type>
Vertex<value_type>::Vertex(
    Vector3D<value_type> _position, Vector3D<value_type> _normal,
    Vector3D<value_type> _texture_coordinate)
    : position(_position), normal(_normal),
      texture_coordinate(_texture_coordinate) {}

template<typename value_type> Vertex<value_type>::~Vertex() {}

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_HPP_
