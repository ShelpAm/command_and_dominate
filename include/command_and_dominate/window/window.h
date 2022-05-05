#ifndef COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_H_
#define COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_H_

#include <map>
#include "small_utility/string/string.h"
#include "command_and_dominate/window/window_forward.h"

using small_utility::string_stuff::String;

// Brief:
//  This class can just create one window and makes it work successfully.
class Window
{
 public:
  static bool const Initialize();
  // Note:
  //  This function must be called after all the function called in opengl
  //   because they will be invalid after calling this.
  static void Terminate();
  static WindowPtr Create(
      int const window_width,
      int const window_height,
      char const *const window_title,
      WindowFramebufferSizeCallback framebuffer_size_callback,
      WindowCharCallback char_callback,
      WindowCursorPositionCallback cursor_position_callback,
      WindowKeyCallback key_callback,
      WindowScrollCallback scroll_callback);
  Window() = delete;
  Window(int const window_width, int const window_height,
         char const *const window_title,
         WindowFramebufferSizeCallback framebuffer_size_callback,
         WindowCharCallback char_callback,
         WindowCursorPositionCallback cursor_position_callback,
         WindowKeyCallback key_callback,
         WindowScrollCallback scroll_callback);
  ~Window();

  static WindowPtr Get(GLFWwindow *const glfw_window_ptr);
  void Use();
  void Delete();

  GLFWwindow *GetGLFWWindowPtr() const { return glfw_window_ptr_; }
  int const GetWindowWidth() const { return window_width_; }
  int const GetWindowHeight() const { return window_height_; }
  String const GetWindowTitle() const { return window_title_; }
  void SetWindowWidth(int const window_width) {
    window_width_ = window_width;
  }
  void SetWindowHeight(int const window_height) {
    window_height_ = window_height;
  }

 private:
  static std::map<GLFWwindow *, WindowPtr> all_;

  GLFWwindow* glfw_window_ptr_;
  WindowFramebufferSizeCallback framebuffer_size_callback_;
  WindowCharCallback char_callback_;
  WindowCursorPositionCallback cursor_position_callback_;
  WindowKeyCallback key_callback_;
  WindowScrollCallback scroll_callback_;

  int window_width_;
  int window_height_;
  String window_title_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_WINDOW_WINDOW_H_
