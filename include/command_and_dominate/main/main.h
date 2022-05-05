#ifndef COMMAND_AND_DOMINATE_SRC_MAIN_MAIN_H_
#define COMMAND_AND_DOMINATE_SRC_MAIN_MAIN_H_

#include "command_and_dominate/glfw.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void char_callback(GLFWwindow *window, unsigned int codepoint);
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);
void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

#endif // !COMMAND_AND_DOMINATE_SRC_MAIN_MAIN_H_
