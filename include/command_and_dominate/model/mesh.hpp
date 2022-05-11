#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_MESH_HPP_
#define COMMAND_AND_DOMINATE_SRC_MODEL_MESH_HPP_

#include "command_and_dominate/glad.h"
#include "command_and_dominate/model/vertex.h"

template<typename value_type> MeshPtr<value_type> Mesh<value_type>::Create(
    std::vector<Vertex<value_type>> vertices,
    std::vector<unsigned int> indices,
    std::vector<Image2DPtr> images) {
  MeshPtr<value_type> mesh_ptr = std::make_shared<Mesh<value_type>>(
      vertices, indices, images);
  return mesh_ptr;
}

template<typename value_type> Mesh<value_type>::Mesh() {
  Initialize();
}

template<typename value_type>
Mesh<value_type>::Mesh(std::vector<Vertex<value_type>> vertices,
                       std::vector<unsigned int> indices,
                       std::vector<Image2DPtr> images)
    : vertices_(vertices), indices_(indices), images_(images) {
  Initialize();
}

template<typename value_type>
Mesh<value_type>::~Mesh() {
  Delete();
}

template<typename value_type>
void Mesh<value_type>::Render(ShaderPtr const &shader_ptr) const {
  glBindVertexArray(vao_);
  glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT,
                 static_cast<void *>(0));
  glBindVertexArray(0);
}

template<typename value_type>
void Mesh<value_type>::Delete() {
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
  glDeleteBuffers(1, &ebo_);
}

template<typename value_type>
void Mesh<value_type>::Initialize() {
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);

  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex<value_type>) * vertices_.size(),
      &(vertices_[0]), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices_.size(),
      &(indices_[0]), GL_STATIC_DRAW);

  // position
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex<value_type>),
      nullptr);
  // normal
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex<value_type>),
      reinterpret_cast<void *>(offsetof(Vertex<value_type>, normal)));
  // texture coordinate
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex<value_type>),
      reinterpret_cast<void *>(
          offsetof(Vertex<value_type>, texture_coordinate)));

  glBindVertexArray(0);
}

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_MESH_HPP_
