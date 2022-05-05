#include "command_and_dominate/game_object/movable_object.h"

MovableObjectPtr MovableObject::Create(
    char const* const name,
    float const mass,
    Vector3D<float> const &force,
    Vector3D<float> const &velocity,
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const* const ui_name) {
  MovableObjectPtr movable_object_ptr = std::make_shared<MovableObject>(
      mass, force, velocity, position, pitch, yaw, scroll, ui_name);
  all_[name] = movable_object_ptr;
  return movable_object_ptr;
}

MovableObject::MovableObject(
    float const mass,
    Vector3D<float> const &force,
    Vector3D<float> const &velocity,
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const *const ui_name)
    : BasicObject(position, pitch, yaw, scroll, ui_name),
      mass_(mass),
      force_(force),
      velocity_(velocity) {}

MovableObject::~MovableObject() {
  Delete();
}

void MovableObject::Update(int const delta_time) {}

void MovableObject::Delete() {}
