#ifndef SMALL_UTILITY_LOG_LOG_TARGET_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_H_

#include "small_utility/string/string.h"

namespace small_utility {

namespace log_stuff {

class LogTarget {
 public:
  virtual void Write(string_stuff::String const &log_message) = 0;
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_H_
