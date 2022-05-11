#version 330 core

in FragmentInput {
  vec3 fragment_position;
  vec3 normal;
  vec2 texture_coordinate;
} fragment_input;

out vec4 FragColor;

void main() {
  vec4 result = vec4(1.0f);

  result.xyz = vec3(1.0f, 1.0f, 0.0f);

  FragColor = result;
}

