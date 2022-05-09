#ifndef COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_IMMOVABLE_OBJECT_H_
#define COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_IMMOVABLE_OBJECT_H_

#include "command_and_dominate/game_object/immovable_object_forward.h"
#include "command_and_dominate/game_object/basic_object.h"
#include "small_utility/math/vector/vector3d.h"

class ImmovableObject : virtual public BasicObject {
 public:
  static ImmovableObjectPtr Create(
      char const *const name = "undefined",
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      float const pitch = 0.0f,
      float const yaw = 0.0f,
      float const scroll = 0.0f,
      char const *const ui_name = "undefined");
  ImmovableObject(
      Vector3D<float> const &position,
      float const pitch, float const yaw, float const scroll,
      char const *const ui_name);

  virtual void Update(int const delta_time);
};

#endif // !COMMAND_AND_DOMINATE_SRC_GAME_OBJECT_IMMOVABLE_OBJECT_H_
