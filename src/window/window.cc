#include "command_and_dominate/window/window.h"
#include <cstdio>
#include <map>
#include <memory>
#include "small_utility/log/logger.h"
#include "small_utility/string/string.h"
#include "command_and_dominate/glad.h"

std::map<GLFWwindow *, WindowPtr> Window::all_;

void Window::Initialize() {
  if (!glfwInit()) {
    using small_utility::string_stuff::String;
    String error_buffer("failed to initialize glfw - error code: ");
    error_buffer += String(glfwGetError(0));
    small_utility::log_stuff::Fatal(error_buffer.ConstData());
    throw WindowUninitialized(error_buffer.ConstData());
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  glfwWindowHint(GLFW_SAMPLES, 4);
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
    char const *const error_buffer = "failed to initialize glad";
    small_utility::log_stuff::Fatal(error_buffer);
    throw std::runtime_error(error_buffer);
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
    small_utility::string_stuff::String error_buffer(
        "glfw failed to make a window - error code: ");
    error_buffer += glfwGetError(0);
    small_utility::log_stuff::Fatal(error_buffer.ConstData());
    throw std::runtime_error(error_buffer.ConstData());
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
