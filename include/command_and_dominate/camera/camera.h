#ifndef COMMAND_AND_DOMINATE_SRC_CAMERA_CAMERA_H_
#define COMMAND_AND_DOMINATE_SRC_CAMERA_CAMERA_H_

#include "command_and_dominate/camera/camera_forward.h"
#include "command_and_dominate/game_object/movable_object.h"
#include "command_and_dominate/model/model_forward.h"

class Camera : MovableObject {
/* public:
  static CameraPtr Create(
      );
  Camera(
      Vector3D<float> const &world_up = Vector3D<float>(0.0f, 1.0f, 0.0f),
      float const mass = 1.0f,
      Vector3D<float> const &force = Vector3D<float>(0.0f),
      Vector3D<float> const &velocity = Vector3D<float>(0.0f),
      ModelPtr const &model_ptr = nullptr,
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      float const pitch = 0.0f,
      float const yaw = 0.0f,
      float const scroll = 0.0f,
      char const *const ui_name = "new rendered_ui");
  Camera(
      Vector3D<float> const &world_up = Vector3D<float>(0.0f, 1.0f, 0.0f),
      Vector3D<float> const &target = Vector3D<float>(0.0f),
      float mass = 1.0f,
      Vector3D<float> force = Vector3D<float>(0.0f),
      Vector3D<float> velocity = Vector3D<float>(0.0f),
      ModelPtr const &model_ptr = nullptr,
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      char const *const ui_name = "new rendered_ui");
  ~Camera();

  void ProcessMouseMovement(float const delta_x_position,
                            float const delta_y_position);
  virtual void Update(float const delta_time);
  void PrintParameters() const;

private:
  static float sensitivity_;
  // This represents the vector pointed by the camera
  //  and should be normalized.
  Vector3D<float> direction_;
  Vector3D<float> target_;
  Vector3D<float> front_;
  Vector3D<float> right_;
  Vector3D<float> world_up_;*/
};

#endif // !COMMAND_AND_DOMINATE_SRC_CAMERA_CAMERA_H_
