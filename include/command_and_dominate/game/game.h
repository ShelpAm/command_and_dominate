#ifndef COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_
#define COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_

#include <vector>
#include "small_utility/math/color/color.h"
#include "command_and_dominate/camera/camera_forward.h"
#include "command_and_dominate/game/game_forward.h"
#include "command_and_dominate/game_object/rendered_object_forward.h"
#include "command_and_dominate/window/window.h"

enum class GameState : int {
  kGameStateOnMenu,
  kGameStateStarted
};

class Game {
 public:
  static void Initialize(int argc, char* argv[]);
  static void Terminate();
  static GamePtr Create(WindowPtr const &window_ptr);
  explicit Game(WindowPtr const &window_ptr);
  ~Game();

  void Run();
  void ProcessInput();
  void ProcessMovementKey();
  void ProcessAxisXZ();
  void ProcessAxisY();
  void Update(float const delta_time);
  void Render() const;
  void Delete();

  WindowPtr GetWindowPtr() { return window_ptr_; }
  bool GetBlend() const { return blend_; }
  bool GetBlendDefault() const { return blend_default_; }
  bool GetPause() const { return pause_; }
  bool GetPauseDefault() const { return pause_default_; }
  std::vector<CameraPtr> const &GetCameraPtrs() const { return camera_ptrs_; }
  void AddCamera(CameraPtr camera_ptr) { camera_ptrs_.push_back(camera_ptr); }

  static bool keys_[348];
  static bool keys_pressed_single_times_[348];

 private:
  WindowPtr window_ptr_;

  Color window_clear_color_;
  bool blend_;
  bool blend_default_;
  bool depth_test_;
  bool depth_test_default_;
  bool pause_;
  bool pause_default_;

  GameState game_state_;

  std::vector<CameraPtr> camera_ptrs_;
  std::vector<RenderedObjectPtr> rendered_object_ptrs_;
};

class GameUninitialized : public std::runtime_error {
 public:
  char const *what() const throw() {
    return "game uninitialized";
  }
};

#endif // !COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_
