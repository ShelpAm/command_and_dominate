#include "command_and_dominate/game_object/game_object.h"

std::map<char const *const, BasicObjectPtr> BasicObject::all_;

BasicObjectPtr BasicObject::Create(
    char const *const name,
    Vector3D<float> const &position,
    float const pitch,
    float const yaw,
    float const scroll,
    char const *const ui_name) {
  BasicObjectPtr basic_object_ptr = std::make_shared<BasicObject>(
      position, pitch, yaw, scroll, ui_name);
  return basic_object_ptr;
}

BasicObject::BasicObject(
    Vector3D<float> const &position,
    float const pitch,
    float const yaw,
    float const scroll,
    char const *const ui_name)
    : position_(position),
      pitch_(pitch),
      yaw_(yaw),
      scroll_(scroll),
      ui_name_(ui_name) {}

BasicObject::~BasicObject() {}
