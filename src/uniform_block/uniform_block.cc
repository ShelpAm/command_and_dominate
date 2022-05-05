#include "command_and_dominate/uniform_block/uniform_block.h"

#include "command_and_dominate/glad.h"

std::map<const char *const, UniformBlockPtr> UniformBlock::all_;

void UniformBlock::Terminate() {
  all_.clear();
}

UniformBlockPtr UniformBlock::Create(char const *const name,
                                     char const *const ui_name,
                                     unsigned int const size,
                                     unsigned int const bind_point) {
  all_[name] = std::make_shared<UniformBlock>(ui_name, size, bind_point);
  glBindBuffer(GL_UNIFORM_BUFFER, all_[name]->GetUbo());
  glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_STATIC_DRAW);
  glBindBufferRange(GL_UNIFORM_BUFFER, bind_point, all_[name]->GetUbo(),
      0, size);
  // Or
  // glBindBufferBase(GL_UNIFORM_BUFFER, bind_point,
  //  uniform_block_ptr->GetUbo());
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
  return all_[name];
}

UniformBlock::UniformBlock(char const *const ui_name,
                           unsigned int const size,
                           unsigned int const bind_point)
    : ui_name_(ui_name),
      size_(size),
      bind_point_(bind_point) {
  glGenBuffers(1, &ubo_);
}

UniformBlock::~UniformBlock() {
  Delete();
}

UniformBlockPtr UniformBlock::Get(char const *const name) {
  auto iterator = all_.find(name);
  if (iterator != all_.end()) {
    return iterator->second;
  }
  printf("[Prompt::UniformBlock::Get] Can not find the UniformBlock named %s.",
         name);
  return nullptr;
}

void UniformBlock::Delete() {
  glDeleteBuffers(1, &ubo_);
}
