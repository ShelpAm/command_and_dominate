#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_FORWARD_H_
#define COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_FORWARD_H_

#include <memory>

template<typename value_type> struct Vertex;
template<typename value_type> using VertexPtr =
    std::shared_ptr<Vertex<value_type>>;

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_VERTEX_FORWARD_H_
