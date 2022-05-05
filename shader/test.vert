#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texture_coordinate;

out FragmentInput {
  vec3 fragment_position;
  vec3 normal;
  vec2 texture_coordinate;
} fragment_input;

layout (std140) uniform matrices {
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
};

uniform vec3 model_position;
uniform mat4 model_rotation; // TODO : Please place this with Matrices::model

void main() {
  vec4 converted_position = vec4(position, 1.0f);
  converted_position *= model_rotation;
  converted_position += vec4(model_position, 1.0f);// The correct value of 1.0
                                                   //  may be 0.0f.
  gl_Position = projection * view * model * converted_position;
  fragment_input.fragment_position = vec3(model * converted_position);
  fragment_input.normal = mat3(transpose(inverse(model))) * normal;
  fragment_input.texture_coordinate = texture_coordinate;

  gl_Position = vec4(0.5f);
}

