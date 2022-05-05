#ifndef COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_TYPE_H_
#define COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_TYPE_H_

#include "command_and_dominate/shader/shader_type_forward.h"

enum class ShaderType : int {
  kShaderTypeProgram,
  kShaderTypeVertexShader,
  kShaderTypeFragmentShader,
  kShaderTypeGeometryShader,
};

#endif // !COMMAND_AND_DOMINATE_SRC_SHADER_SHADER_TYPE_H_
