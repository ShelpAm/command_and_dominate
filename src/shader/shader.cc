#include "command_and_dominate/shader/shader.h"
#include <cstdio>
#include <cstring>
#include "command_and_dominate/math/math.h"
#include "command_and_dominate/shader/shader_type.h"
#include "command_and_dominate/uniform_block/uniform_block.h"

std::map<char const *const, ShaderPtr> Shader::all_;

void Shader::Terminate() {
  all_.clear();
}

ShaderPtr Shader::Create(char const *const name,
                         char const *const vertex_file_name,
                         char const *const fragment_file_name,
                         char const *const geometry_file_name) {
  char const *const filenames[3] = {vertex_file_name,
                                    fragment_file_name,
                                    geometry_file_name};
  // compile shaders from files, and attach them to the shader program.
  FILE *file_ptrs[3];
  unsigned int shader_id;
  int file_size;
  for (int i = 0; i != 3; ++i) {
    file_ptrs[i] = fopen(filenames[i], "rb");
    if (!file_ptrs[i]) {
      printf("[ERROR::Shader::Create] Failed to load file: %s.\n",
             filenames[i]);
      for (int j = 0; j != i; ++j) {
        fclose(file_ptrs[j]);
      }
      return nullptr;
    }
  }
  all_[name] = std::make_shared<Shader>();
  for (int i = 0; i != 3; ++i) {
    fseek(file_ptrs[i], 0, SEEK_END);
    file_size = ftell(file_ptrs[i]);
    fseek(file_ptrs[i], 0, SEEK_SET);
    char *buffer = new char[file_size + 1];
    fread(buffer, file_size, 1, file_ptrs[i]);
    fclose(file_ptrs[i]);
    //printf("[Debug::Shader::Create] buffer:\n%s\n", buffer);
    if (i == 0) {
      shader_id = glCreateShader(GL_VERTEX_SHADER);
    } else if (i == 1) {
      shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    } else if (i == 2) {
      shader_id = glCreateShader(GL_GEOMETRY_SHADER);
    }
    glShaderSource(shader_id, 1, &buffer, 0);
    glCompileShader(shader_id);
    CheckErrors(shader_id, static_cast<ShaderType>(i + 1));
    glAttachShader(all_[name]->GetId(), shader_id);
    glDeleteShader(shader_id); // This just sets the need_deleting flag.
    delete[] buffer;
  }
  glLinkProgram(all_[name]->GetId());
  CheckErrors(all_[name]->GetId(), ShaderType::kShaderTypeProgram);
  return all_[name];
}

Shader::Shader() : id_(glCreateProgram()) {}

Shader::~Shader() {
  Delete();
}

ShaderPtr Shader::Get(char const *const name) {
  auto iterator = all_.find(name);
  if (iterator != all_.end()) {
    return iterator->second;
  }
  printf("[Prompt::Shader::Get] Can not find the Shader named %s.\n", name);
  return nullptr;
}

void Shader::Use() {
  glUseProgram(id_);
}

void Shader::BindUniformBlock(UniformBlockPtr const &uniform_block_ptr) {
  glUniformBlockBinding(
      id_,
      glGetUniformBlockIndex(id_, uniform_block_ptr->GetUiName()),
      uniform_block_ptr->GetBindPoint());
}

void Shader::Delete() {
  glDeleteProgram(id_);
}

//void Shader::SetLight(char const *const name, LightPtr const &light_ptr) {
//  
//}

void Shader::Set1Int(char const *const name, int const value) {
  glUniform1i(GetUniformLocation(name), value);
}

void Shader::Set1Bool(char const *const name, bool const value) {
  Set1Int(name, static_cast<int const>(value));
}

void Shader::Set1Float(char const *const name, float const value) {
  glUniform1f(GetUniformLocation(name), value);
}

template<typename value_type>
void Shader::SetVector2D(char const *const name,
                         Vector2DPtr<value_type> const& vector2d_ptr) {
  glUniform2fv(GetUniformLocation(name), 1, GetValuePtr(vector2d_ptr));
}

template<typename value_type>
void Shader::SetVector3D(char const *const name,
                         Vector3DPtr<value_type> const& vector3d_ptr) {
  glUniform3fv(GetUniformLocation(name), 1, GetValuePtr(vector3d_ptr));
}

template<typename value_type>
void Shader::SetMatrix4x4(char const *const name,
                          Matrix4x4Ptr<value_type> const& matrix4x4_ptr) {
  glUniformMatrix4fv(GetUniformLocation(name), 1, false,
                     GetValuePtr(matrix4x4_ptr));
}

void Shader::CheckErrors(unsigned int const id,
                         ShaderType const shader_type) {
  int successful;
  char const *shader_type_string;
  if (shader_type == ShaderType::kShaderTypeProgram) {
    glGetProgramiv(id, GL_LINK_STATUS, &successful);
    shader_type_string = "program";
  } else if (shader_type == ShaderType::kShaderTypeVertexShader) {
    glGetShaderiv(id, GL_COMPILE_STATUS, &successful);
    shader_type_string = "vertex_shader";
  } else if (shader_type == ShaderType::kShaderTypeFragmentShader){
    glGetShaderiv(id, GL_COMPILE_STATUS, &successful);
    shader_type_string = "fragment_shader";
  } else if (shader_type == ShaderType::kShaderTypeGeometryShader){
    glGetShaderiv(id, GL_COMPILE_STATUS, &successful);
    shader_type_string = "geometry_shader";
  }
  if (!successful) {
    char info_log[512] = { 0 };
    if (shader_type == ShaderType::kShaderTypeProgram) {
      glGetProgramInfoLog(id, 511, nullptr, info_log);
    } else {
      glGetShaderInfoLog(id, 511, nullptr, info_log);
    }
    printf("[Prompt::Shader::CheckErrors] ------------------------------\n"
           "Some errors have occurred in %s, info:\n"
           "%s\n"
           "------------------------------------------------------------\n",
           shader_type_string, info_log);
  }
}
