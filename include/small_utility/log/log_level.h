#ifndef SMALL_UTILITY_LOG_LOG_LEVEL_H_
#define SMALL_UTILITY_LOG_LOG_LEVEL_H_

namespace small_utility {

namespace log_stuff {

enum LogLevel : int {
  kLogLevelDebug = 1,
  kLogLevelInfo,
  kLogLevelWarn,
  kLogLevelError,
  kLogLevelFatal
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_LEVEL_H_
