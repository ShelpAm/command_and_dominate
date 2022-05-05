#include "command_and_dominate/window/window.h"
#include <cstdio>
#include <map>
#include <memory>
#include "command_and_dominate/glad.h"

std::map<GLFWwindow *, WindowPtr> Window::all_;

bool const Window::Initialize() {
  if (!glfwInit()) {
    printf("[ERROR::Window::Initialize] Failed to initialize glfw. "
           "Error code: %i.\n", glfwGetError(0));
    return false;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  glfwWindowHint(GLFW_SAMPLES, 4);
  return true;
}

void Window::Terminate() {
  glfwTerminate();
}

WindowPtr Window::Create(
    int const window_width, int const window_height,
    char const *const window_title,
    WindowFramebufferSizeCallback framebuffer_size_callback,
    WindowCharCallback char_callback,
    WindowCursorPositionCallback cursor_position_callback,
    WindowKeyCallback key_callback,
    WindowScrollCallback scroll_callback) {
  WindowPtr window_ptr = std::make_shared<Window>(
      window_width, window_height,
      window_title,
      framebuffer_size_callback,
      char_callback,
      cursor_position_callback,
      key_callback,
      scroll_callback);
  if (!window_ptr->glfw_window_ptr_) {
    return nullptr;
  }
  window_ptr->Use();// glfwMakeContextCurrent(window_ptr->glfw_window_ptr_);
  //glfwSetInputMode(window_ptr->glfw_window_ptr_, GLFW_CURSOR,
  //                 GLFW_CURSOR_DISABLED);
  glfwSetFramebufferSizeCallback(window_ptr->glfw_window_ptr_,
                                 framebuffer_size_callback);
  glfwSetCharCallback(window_ptr->glfw_window_ptr_, char_callback);
  glfwSetCursorPosCallback(window_ptr->glfw_window_ptr_,
                           cursor_position_callback);
  glfwSetKeyCallback(window_ptr->glfw_window_ptr_, key_callback);
  glfwSetScrollCallback(window_ptr->glfw_window_ptr_, scroll_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("[ERROR::Window::Window] Failed to initialize glad.\n");
    return nullptr;
  }
  all_[window_ptr->GetGLFWWindowPtr()] = window_ptr;
  return window_ptr;
}

Window::Window(int const window_width, int const window_height,
               char const *const window_title,
               WindowFramebufferSizeCallback framebuffer_size_callback,
               WindowCharCallback char_callback,
               WindowCursorPositionCallback cursor_position_callback,
               WindowKeyCallback key_callback,
               WindowScrollCallback scroll_callback)
    : window_width_(window_width),
      window_height_(window_height),
      window_title_(window_title),
      framebuffer_size_callback_(framebuffer_size_callback),
      char_callback_(char_callback),
      cursor_position_callback_(cursor_position_callback),
      key_callback_(key_callback),
      scroll_callback_(scroll_callback) {
  glfw_window_ptr_ = glfwCreateWindow(window_width, window_height,
                                      window_title, nullptr, nullptr);
  if(!glfw_window_ptr_) {
    printf("[ERROR::Window::Window] Failed to create a window. "
           "Error code: %i.\n", glfwGetError(0));
  }
}

Window::~Window() {
  Delete();
}

void Window::Use() {
  glfwMakeContextCurrent(glfw_window_ptr_);
}

void Window::Delete() {
  glfwDestroyWindow(glfw_window_ptr_);
}

WindowPtr Window::Get(GLFWwindow *const glfw_window_ptr) {
  auto iterator = all_.find(glfw_window_ptr);
  if (iterator != all_.end()) {
    return iterator->second;
  }
  printf("[Prompt::Window::Get] Can not find the Window of %p.\n",
         glfw_window_ptr);
  return nullptr;
}
