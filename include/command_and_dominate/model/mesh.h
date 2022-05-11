#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_MESH_H_
#define COMMAND_AND_DOMINATE_SRC_MODEL_MESH_H_

#include <vector>
#include "command_and_dominate/image/image2d_forward.h"
#include "command_and_dominate/model/mesh_forward.h"
#include "command_and_dominate/shader/shader_forward.h"
#include "command_and_dominate/model/vertex_forward.h"

template<typename value_type> class Mesh {
 public:
  static MeshPtr<value_type> Create(std::vector<VertexPtr<value_type>> vertices,
                                    std::vector<unsigned int> indices,
                                    std::vector<Image2DPtr> images);
  Mesh();
  Mesh(std::vector<VertexPtr<value_type>> vertices,
       std::vector<unsigned int> indices,
       std::vector<Image2DPtr> images);
  ~Mesh();

  void Render(ShaderPtr const &shader_ptr) const;
  void Delete();

 private:
  void Initialize();

  unsigned int vao_, vbo_, ebo_;
  std::vector<Vertex<value_type>> vertices_;
  std::vector<unsigned int> indices_;
  std::vector<Image2DPtr> images_;
};

#include "command_and_dominate/model/mesh.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_MESH_H_
