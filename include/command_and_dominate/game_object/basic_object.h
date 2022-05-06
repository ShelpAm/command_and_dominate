#ifndef COMMAND_AND_DOMINATE_GAME_OBJECT_BASIC_OBJECT_H_
#define COMMAND_AND_DOMINATE_GAME_OBJECT_BASIC_OBJECT_H_

#include "command_and_dominate/game_object/basic_object_forward.h"
#include <map>
#include "small_utility/string/string.h"
#include "small_utility/math/vector/vector3d.h"

using small_utility::string_stuff::String;

class BasicObject {
 public:
  static BasicObjectPtr Create(
      char const *const name,
      Vector3D<float> const &position = Vector3D<float>(0.0f),
      float const pitch = 0.0f,
      float const yaw = 0.0f,
      float const scroll = 0.0f,
      char const *const ui_name = nullptr);
  BasicObject(
      Vector3D<float> const &position,
      float const pitch, float const yaw, float const scroll,
      char const *const ui_name);
  virtual ~BasicObject();

  Vector3D<float> const GetPosition() const { return position_; }
  String const GetUiName() { return ui_name_; }
  float const GetPitch() const { return pitch_; }
  float const GetYaw() const { return yaw_; }
  float const GetScoll() const { return scroll_; }
  void SetPosition(Vector3D<float> const &position) { position_ = position; }
  void SetPitch(float const pitch) { pitch_ = pitch; }
  void SetYaw(float const yaw) { yaw_ = yaw; }
  void SetScroll(float const scroll) { scroll_ = scroll; }
  void SetUiName(char const *const ui_name) { ui_name_ = ui_name; }
  void AddPosition(Vector3D<float> const &delta_position) {
    position_ += delta_position;
  }
  void AddPitch(float const delta_pitch) { pitch_ += delta_pitch; }
  void AddYaw(float const delta_yaw) { yaw_ += delta_yaw; }
  void AddScroll(float const delta_scroll) { scroll_ = delta_scroll; }

 protected:
  static std::map<char const *const, BasicObjectPtr> all_;

 private:
  Vector3D<float> position_;
  // The following three member datas use radians.
  float pitch_;
  float yaw_;
  float scroll_;
  String ui_name_;
};

#endif  // COMMAND_AND_DOMINATE_GAME_OBJECT_BASIC_OBJECT_H_
