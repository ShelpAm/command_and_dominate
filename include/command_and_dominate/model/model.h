#ifndef COMMAND_AND_DOMINATE_SRC_MODEL_MODEL_H_
#define COMMAND_AND_DOMINATE_SRC_MODEL_MODEL_H_

#include "command_and_dominate/model/model_forward.h"
#include <vector>
#include <map>
#include "command_and_dominate/model/mesh.h"

template<typename value_type> class Model {
 public:
  static ModelPtr Create(char const *const name, char const *const filename);
  static ModelPtr Create(
      char const *const name,
      std::vector<MeshPtr<value_type>> mesh_ptrs);
  Model(std::vector<MeshPtr<value_type>> mesh_ptrs);

 private:
  static std::map<small_utility::string_stuff::String const &,
                  MeshPtr<value_type>> all_;

  std::vector<MeshPtr<value_type>> mesh_ptrs_;
};

#include "command_and_dominate/model/model.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MODEL_MODEL_H_
