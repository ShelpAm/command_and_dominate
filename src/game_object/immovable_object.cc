#include "command_and_dominate/game_object/immovable_object.h"
#include "command_and_dominate/shader/shader_forward.h"

ImmovableObjectPtr Create(
    char const *const name,
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const *const ui_name) {
  ImmovableObjectPtr immovable_object_ptr =
      std::make_shared<ImmovableObject>(position, pitch, yaw, scroll, ui_name);
  return immovable_object_ptr;
}

ImmovableObject::ImmovableObject(
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const *const ui_name)
    : BasicObject(position, pitch, yaw, scroll, ui_name) {}

void ImmovableObject::Update(int const delta_time) {}
