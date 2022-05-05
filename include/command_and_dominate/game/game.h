#ifndef COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_
#define COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_

#include <vector>

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
  static bool Initialize(int argc, char* argv[]);
  static void Terminate();
  static GamePtr Create(WindowPtr const &window_ptr);
  Game() = delete;
  Game(WindowPtr const &window_ptr);
  ~Game();

  void Run();
  void ProcessInput();
  void ProcessMovementKey();
  void ProcessXZAxis();
  void ProcessYAxis();
  void Update();
  void Render() const;
  void Delete();

  WindowPtr GetWindowPtr() { return window_ptr_; }
  bool const GetBlend() const { return blend_; }
  bool const GetBlendDefault() const { return blend_default_; }
  float const GetFramePerSecond() const { return 1.0f / delta_time_; }
  bool const GetPause() const { return pause_; }
  bool const GetPauseDefault() const { return pause_default_; }
  std::vector<CameraPtr> GetCameraPtrs() const { return camera_ptrs_; }
  void AddCamera(CameraPtr camera_ptr) {
    camera_ptrs_.push_back(camera_ptr);
  }

  static bool keys_[348];
  static bool keys_pressed_single_times_[348];

 private:
  WindowPtr window_ptr_;

  bool blend_;
  bool blend_default_;
  bool depth_test_;
  bool depth_test_default_;
  bool pause_;
  bool pause_default_;

  // The units of following are all milliseconds.
  int begin_time_;
  int end_time_;
  int delta_time_;
  //float frame_per_second_;

  GameState state_;

  std::vector<CameraPtr> camera_ptrs_;
  std::vector<RenderedObjectPtr> rendered_object_ptrs_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_GAME_GAME_H_
