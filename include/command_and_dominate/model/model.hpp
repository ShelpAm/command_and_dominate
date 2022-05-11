template<typename value_type> ModelPtr<value_type> Model<value_type>::Create(
    char const *const name, char const *const filename) {
  // Load model from file.
  // And call the other Create function.
  std::vector<MeshPtr<value_type>> mesh_ptrs;


  return Model::Create(name, mesh_ptrs);
}

template<typename value_type> ModelPtr<value_type> Model<value_type>::Create(
    char const *const name, std::vector<MeshPtr<value_type>> mesh_ptrs) {
  all_[name] = std::make_shared<Model>(mesh_ptrs);
  return all_[name];
}

template<typename value_type> Model<value_type>::Model(
    std::vector<MeshPtr> mesh_ptrs) : mesh_ptrs_(mesh_ptrs) {}
