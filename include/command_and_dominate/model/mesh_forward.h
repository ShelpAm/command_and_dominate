#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_MESH_FORWARD_H_
#define COMMAND_AND_DOMINATE_SRC_MODEL_MESH_FORWARD_H_

#include <memory>

template<typename value_type> class Mesh;
template<typename value_type> using MeshPtr =
    std::shared_ptr<Mesh<value_type>>;

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_MESH_FORWARD_H_
