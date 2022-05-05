#include "command_and_dominate/game_object/rendered_object.h"
#include "command_and_dominate/shader/shader_forward.h"
#include <cstdio>

RenderedObjectPtr RenderedObject::Create(
    char const *const name,
    ModelPtr<float> const &model_ptr,
    float const mass,
    Vector3D<float> const &force, Vector3D<float> const &velocity,
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const *const ui_name) {
  RenderedObjectPtr rendered_object_ptr =
      std::make_shared<RenderedObject>(
          model_ptr, mass, force, velocity,
          position, pitch, yaw, scroll, ui_name);
  all_[name] = rendered_object_ptr;
  return rendered_object_ptr;
}

RenderedObject::RenderedObject(
    ModelPtr<float> const &model_ptr,
    float const mass,
    Vector3D<float> const &force, Vector3D<float> const &velocity,
    Vector3D<float> const &position,
    float const pitch, float const yaw, float const scroll,
    char const *const ui_name)
    : BasicObject(position, pitch, yaw, scroll, ui_name),
      MovableObject(mass, force, velocity,
                    position, pitch, yaw, scroll, ui_name),
      ImmovableObject(position, pitch, yaw, scroll, ui_name),
      model_ptr_(model_ptr) {}

RenderedObject::~RenderedObject() {}

void RenderedObject::Render(ShaderPtr const &shader_ptr) const {}

void RenderedObject::Update(int const delta_time) {
  AddPosition(GetVelocity() * (delta_time / 1000.0f));
  AddVelocity(GetAcceleration() * (delta_time / 1000.0f));
  UpdateAcceleration();
  //SetForce(Vector3D<float>(0.0f)); // TODO(small_sheep): This should be
                                     //   attached to phisical engine.
}
