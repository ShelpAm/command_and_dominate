#ifndef COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_RENDERED_OBJECT_H_
#define COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_RENDERED_OBJECT_H_

#include "command_and_dominate/game_object/rendered_object_forward.h"
#include "command_and_dominate/game_object/movable_object.h"
#include "command_and_dominate/game_object/immovable_object.h"
#include "small_utility/math/vector/vector3d.h"
#include "command_and_dominate/model/model_forward.h"
#include "command_and_dominate/shader/shader_forward.h"

class RenderedObject
    : public MovableObject,
      public ImmovableObject {
 public:
  static RenderedObjectPtr Create(
      char const *const name = "undefined",
      ModelPtr<float> const &model_ptr = nullptr,
      float const mass = 1.0f,
      Vector3D<float> const &force = Vector3D<float>(0.0f),
      Vector3D<float> const &velocity = Vector3D<float>(0.0f),
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      float const pitch = 0.0f,
      float const yaw = 0.0f,
      float const scroll = 0.0f,
      char const *const ui_name = "undefined");
  RenderedObject(
      ModelPtr<float> const &model_ptr,
      float const mass,
      Vector3D<float> const &force, Vector3D<float> const &velocity,
      Vector3D<float> const &position,
      float const pitch, float const yaw, float const scroll,
      char const *const ui_name);
  ~RenderedObject();

  virtual void Render(ShaderPtr const &shader_ptr) const;
  virtual void Update(int const delta_time);

  ModelPtr<float> const GetModelPtr() const { return model_ptr_; }
  void SetModelPtr(ModelPtr<float> const &model_ptr) { model_ptr_ = model_ptr; }

 private:
  ModelPtr<float> model_ptr_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_RENDERED_OBJECT_H_
