#ifndef COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_MOVABLE_OBJECT_H_
#define COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_MOVABLE_OBJECT_H_

#include "command_and_dominate/game_object/movable_object_forward.h"
#include "command_and_dominate/game_object/basic_object.h"
#include "small_utility/math/vector/vector3d.h"
#include "command_and_dominate/shader/shader_forward.h"

class MovableObject : virtual public BasicObject {
 public:
  static MovableObjectPtr Create(
      char const *const name = "undefined",
      float const mass = 1.0f,
      Vector3D<float> const &force = Vector3D<float>(0.0f),
      Vector3D<float> const &velocity = Vector3D<float>(0.0f),
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      float const pitch = 0.0f,
      float const yaw = 0.0f,
      float const scroll = 0.0f,
      char const *const ui_name = "undefined");
  MovableObject(
      float const mass,
      Vector3D<float> const &force,
      Vector3D<float> const &velocity,
      Vector3D<float> const &position,
      float const pitch,
      float const yaw,
      float const scroll,
      char const *const ui_name);
  ~MovableObject();

  //virtual void Render(ShaderPtr const &shader_ptr) const;
  virtual void Update(int const delta_time);
  void Delete();

  float const GetMass() const { return mass_; }
  Vector3D<float> const GetForce() const { return force_; }
  Vector3D<float> const GetAcceleration() const { return acceleration_; }
  Vector3D<float> const GetVelocity() const { return velocity_; }
  void SetMass(float const mass) { mass_ = mass; }
  void SetForce(Vector3D<float> const &force) { force_ = force; }
  void SetVelocity(Vector3D<float> const &velocity) { velocity_ = velocity; }
  void AddMass(float const delta_mass) { mass_ += delta_mass; }
  void AddForce(Vector3D<float> const &delta_force) { force_ += delta_force; }
  void AddVelocity(Vector3D<float> const &delta_velocity) {
    velocity_ += delta_velocity;
  }
  void UpdateAcceleration() { acceleration_ = force_ / mass_; }

 private:
  float mass_;
  // The unit of following 3 parameters are m/s.
  Vector3D<float> force_;
  Vector3D<float> acceleration_;
  Vector3D<float> velocity_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_MOVABLE_OBJECT_H_
