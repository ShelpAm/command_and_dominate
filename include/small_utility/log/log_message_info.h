#ifndef SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
#define SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_

#include "small_utility/string/string.h"

namespace small_utility {

namespace log_stuff {

struct LogMessageInfo {
 public:
  string_stuff::String message;
  LogLevel log_level;
};

} // namespace log_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
