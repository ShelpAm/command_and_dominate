#ifndef COMMAND_AND_DOMINATE_SRC_UNIFORM_BLOCK_UNIFORM_BLOCK_H_
#define COMMAND_AND_DOMINATE_SRC_UNIFORM_BLOCK_UNIFORM_BLOCK_H_

#include "command_and_dominate/uniform_block/uniform_block_forward.h"
#include <map>
#include "small_utility/string/string.h"
#include "command_and_dominate/glad.h"
#include "small_utility/math/type_ptr.h"

using small_utility::string_stuff::String;

class UniformBlock {
 public:
  static void Terminate();
  static UniformBlockPtr Create(char const *const name,
                                char const *const ui_name,
                                unsigned int const size,
                                unsigned int const bind_point);
  UniformBlock() = delete;
  UniformBlock(char const *const name,
               unsigned int const size,
               unsigned int const bind_point);
  ~UniformBlock();

  static UniformBlockPtr Get(char const *const name);
  template<typename data_type> using DataPtr = std::shared_ptr<data_type>;
  template<typename data_type> void FillBuffer(
      int const offset, DataPtr<data_type> const &data_ptr) {
    glBindBuffer(GL_UNIFORM_BUFFER, ubo_);
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(data_type),
        GetValuePtr(data_ptr));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
  }
  void Delete();

  unsigned int const GetUbo() const { return ubo_; }
  unsigned int const GetBindPoint() const { return bind_point_; }
  char const *const GetUiName() const { return ui_name_.ConstData(); }

 private:
  static std::map<char const *const, UniformBlockPtr> all_;

  unsigned int ubo_;
  unsigned int size_;
  unsigned int bind_point_;
  String ui_name_;
};

#endif // !COMMAND_AND_DOMINATE_SRC_UNIFORM_BLOCK_UNIFORM_BLOCK_H_
