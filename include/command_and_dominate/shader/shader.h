#ifndef COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_H_
#define COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_H_

#include "command_and_dominate/shader/shader_forward.h"
#include <map>
#include "command_and_dominate/glad.h"
#include "command_and_dominate/math/math.h"
#include "command_and_dominate/shader/shader_type_forward.h"
#include "command_and_dominate/uniform_block/uniform_block_forward.h"

class Shader {
 public:
  static void Terminate();
  static ShaderPtr Create(
      char const *const name,
      char const *const vertex_file_name,
      char const *const fragment_file_name,
      char const *const geometry_file_name);
  Shader();
  ~Shader();

  static ShaderPtr Get(char const *const name);
  void Use();
  void BindUniformBlock(UniformBlockPtr const &uniform_block_ptr);
  void Delete();
  //void SetLight(char const *const name, LightPtr const &light_ptr);
  void Set1Int(char const *const name, int const value);
  void Set1Bool(char const *const name, bool const value);
  void Set1Float(char const *const name, float const value);
  template<typename value_type> void SetVector2D(char const *const name,
                   Vector2DPtr<value_type> const &vector2d_ptr);
  template<typename value_type> void SetVector3D(char const *const name,
                   Vector3DPtr<value_type> const &vector3d_ptr);
  template<typename value_type> void SetMatrix4x4(char const *const name,
                    Matrix4x4Ptr<value_type> const &matrix4x4_ptr);

  unsigned int const GetId() const { return id_; }
  int const GetUniformLocation(char const *const name) const {
    return glGetUniformLocation(id_, name);
  }

 private:
  static void CheckErrors(unsigned int const id, ShaderType const shader_type);

  static std::map<char const *const, ShaderPtr> all_;
  unsigned int id_;
};


#endif // !COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_H_
