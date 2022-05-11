#include "command_and_dominate/main/main.h"
#include <cstdio>
#include <exception>
#include "small_utility/log/logger.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "command_and_dominate/camera/camera.h"
#include "command_and_dominate/game/game.h"
//#include "command_and_dominate/game_object/game_object.h"
//#include "command_and_dominate/macro/macro.h"
//#include "command_and_dominate/model/mesh.h"
#include "command_and_dominate/model/vertex.h"
#include "command_and_dominate/window/key_type.h"
#include "command_and_dominate/window/window.h"

// glfw: whenever the window size changed (by OS or user resize) this callback
//  function execute
// note that width and height will be significantly larger than specified on retina displays.
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
  Window::Get(window)->SetWindowWidth(width);
  Window::Get(window)->SetWindowHeight(height);
  using small_utility::string_stuff::String;
  String debug_buffer;
  debug_buffer += String("window --width ") += String(width)
               += String(" --height ") += String(height);
  small_utility::log_stuff::Debug(debug_buffer);
}

// This is used for function "mouse_callback".
double last_x = 0;
double last_y = 0;
bool first_mouse = true;

void char_callback(GLFWwindow *window, unsigned int codepoint) {}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
    int mods) {
  KeyType key_type;
  if (key >= 48 && key < 58) {
    key_type = KeyType::kKeyTypeNumberKey;
  } else if (key >= 65 && key < 91 ) {
    key_type = KeyType::kKeyTypeLetterKey;
  } else {
    key_type = KeyType::kKeyTypeNonprintableKey;
  }

  if (action == GLFW_PRESS) {
    Game::keys_[key] = true;
    Game::keys_pressed_single_times_[key] =
      !Game::keys_pressed_single_times_[key];
    if (key_type == KeyType::kKeyTypeNumberKey) {
    } else if (key_type == KeyType::kKeyTypeLetterKey) {
      Game::keys_[key + 32] = true;
      Game::keys_pressed_single_times_[key + 32] =
        !Game::keys_pressed_single_times_[key + 32];
    } else if (key_type == KeyType::kKeyTypeNonprintableKey) {
    }
  }
  if (action == GLFW_RELEASE) {
    Game::keys_[key] = false;
    if (key_type == KeyType::kKeyTypeNumberKey) {
    } else if (key_type == KeyType::kKeyTypeLetterKey) {
      Game::keys_[key + 32] = false;
    } else if (key_type == KeyType::kKeyTypeNonprintableKey){
    }
  }
}

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
  double delta_x = 0, delta_y = 0;
  if (first_mouse) {
    last_x = xpos;
    last_y = ypos;
    first_mouse = false;
  }

  delta_x = xpos - last_x;
  delta_y = ypos - last_y;

  last_x = xpos;
  last_y = ypos;

  //  Game::GetCameras().ProcessMouseMovement(static_cast<float>(delta_x),
  //                                 static_cast<float>(delta_y));
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  printf("[Message::scroll_callback] yoffset: %f.", yoffset);
}

int main(int argc, char *argv[]) {
  try {
    Game::Initialize(argc, argv);

    WindowPtr window_ptr = Window::Create(
        400, 300, "undefined", framebuffer_size_callback, char_callback,
        cursor_position_callback, key_callback, scroll_callback);

    GamePtr game_ptr = Game::Create(window_ptr);
    game_ptr->Run();
    game_ptr->Delete();

  } catch (std::exception const &e) {
    Game::Terminate();
    return 0;
  }

  Game::Terminate();
  return 0;
}
