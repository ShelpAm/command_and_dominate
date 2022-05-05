#ifndef COMMAND_AND_DOMINIATE_SRC_MODEL_MODEL_FORWARD_H_
#define COMMAND_AND_DOMINIATE_SRC_MODEL_MODEL_FORWARD_H_

#include <memory>

template<typename value_type> class Model;
template<typename value_type> using ModelPtr =
    std::shared_ptr<Model<value_type>>;

#endif // !COMMAND_AND_DOMINIATE_SRC_MODEL_MODEL_FORWARD_H_
