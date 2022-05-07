#include "command_and_dominate/main/main.h"
#include <cstdio>
#include "command_and_dominate/glad.h"
#include "command_and_dominate/glfw.h"
#include "command_and_dominate/camera/camera.h"
#include "command_and_dominate/game/game.h"
#include "command_and_dominate/game_object/game_object.h"
#include "command_and_dominate/model/mesh.h"
#include "command_and_dominate/model/vertex.h"
#include "command_and_dominate/window/key_type.h"
#include "command_and_dominate/window/window.h"

//GamePtr game_ptr;

int main(int argc, char *argv[]) {
  printf("linux, command_and_dominate is coming!wtffff\n");

  if (!Game::Initialize(argc, argv)) {
    return -1;
  }

  WindowPtr window_ptr = Window::Create(
      400, 300, "new_window",
      framebuffer_size_callback,
      char_callback,
      cursor_position_callback,
      key_callback,
      scroll_callback);

  printf("break point2\n");

  GamePtr game_ptr = Game::Create(window_ptr);
  if (!game_ptr) {
    return -2;
  }

  printf("break point1\n");

  game_ptr->Run();
  game_ptr->Delete();

  Game::Terminate();
  return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback
//  function execute
// note that width and height will be significantly larger than specified on retina displays.
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
  Window::Get(window)->SetWindowWidth(width);
  Window::Get(window)->SetWindowHeight(height);
  printf("[Debug::framebuffer_size_callback] width: %i, height: %i.\n", width,
      height);
}

// This is used for function "mouse_callback".
double last_x = 0;
double last_y = 0;
bool first_mouse = true;

void char_callback(GLFWwindow *window, unsigned int codepoint) {}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
    int mods) {
  KeyType key_type;
  if (key >= 48 && key < 58) { key_type = KeyType::kKeyTypeNumberKey;
  } else if (key >= 65 && key < 91 ) { key_type = KeyType::kKeyTypeLetterKey;
  } else { key_type = KeyType::kKeyTypeNonprintableKey; }

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

void cursor_position_callback(GLFWwindow *window,
    double xpos, double ypos) {
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
