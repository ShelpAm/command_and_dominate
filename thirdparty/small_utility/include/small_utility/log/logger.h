#ifndef SMALL_UTILITY_LOG_LOGGER_H_
#define SMALL_UTILITY_LOG_LOGGER_H_

#include <vector>
#include "small_utility/log/log_level.h"
#include "small_utility/log/log_message_info.h"
#include "small_utility/log/log_target.h"
#include "small_utility/macro/macro.h"
#include "small_utility/string/string.h"
#include "small_utility/time/time_forward.h"

namespace small_utility {

namespace log_stuff {

class Logger {
 public:
  static Logger &Instance();

  void AddLogMessageInfo(LogMessageInfo const &log_message_info);

  // The target argument has following values:
  //  "console" -> console
  //  others -> file
  void WriteToTarget(char const *const target);

  string_stuff::String const &PatternDefault() const {
    return pattern_default_;
  }

  void SetPatternDefault(char const *const pattern_default) {
    pattern_default_ = pattern_default;
  }

  void SetLogLevelMinimum(LogLevel const log_level_minimum) {
    log_level_minimum_ = log_level_minimum;
  }

  void Debug(char const *const pattern, string_stuff::String const &message,
             int const line, char const *const file_name,
             char const *const function_name);
  void Debug(string_stuff::String const &message, int const line,
             char const *const file_name, char const *const function_name);
  void Info(char const *const pattern, string_stuff::String const &message,
            int const line, char const *const file_name,
            char const *const function_name);
  void Info(string_stuff::String const &message, int const line,
            char const *const file_name, char const *const function_name);
  void Warn(char const *const pattern, string_stuff::String const &message,
            int const line, char const *const file_name,
            char const *const function_name);
  void Warn(string_stuff::String const &message, int const line,
            char const *const file_name, char const *const function_name);
  void Error(char const *const pattern, string_stuff::String const &message,
             int const line, char const *const file_name,
             char const *const function_name);
  void Error(string_stuff::String const &message, int const line,
             char const *const file_name, char const *const function_name);
  void Fatal(char const *const pattern, string_stuff::String const &message,
             int const line, char const *const file_name,
             char const *const function_name);
  void Fatal(string_stuff::String const &message, int const line,
             char const *const file_name, char const *const function_name);
#define Debug(...) Logger::Instance().Debug(__VA_ARGS__, SMALL_UTILITY_LINE,\
                                            SMALL_UTILITY_FILE_NAME,\
                                            SMALL_UTILITY_FUNCTION_NAME)
#define Info(...) Logger::Instance().Info(__VA_ARGS__, SMALL_UTILITY_LINE,\
                                          SMALL_UTILITY_FILE_NAME,\
                                          SMALL_UTILITY_FUNCTION_NAME)
#define Warn(...) Logger::Instance().Warn(__VA_ARGS__, SMALL_UTILITY_LINE,\
                                          SMALL_UTILITY_FILE_NAME,\
                                          SMALL_UTILITY_FUNCTION_NAME)
#define Error(...) Logger::Instance().Error(__VA_ARGS__, SMALL_UTILITY_LINE,\
                                            SMALL_UTILITY_FILE_NAME,\
                                            SMALL_UTILITY_FUNCTION_NAME)
#define Fatal(...) Logger::Instance().Fatal(__VA_ARGS__, SMALL_UTILITY_LINE,\
                                            SMALL_UTILITY_FILE_NAME,\
                                            SMALL_UTILITY_FUNCTION_NAME)

 private:
  std::vector<LogMessageInfo> log_message_infos_;
  string_stuff::String pattern_default_;
  LogLevel log_level_minimum_;
};

int ProcessLogMessage(
      string_stuff::String const &pattern, string_stuff::String const &message,
      int const line, char const *const file_name,
      char const *const function_name, LogLevel const log_level,
      /* out */ string_stuff::String &log_message);

//  destination: The output of this function. Its size_ shouldn't exceed
//    max_function_name_size_.
//  raw_function_name: The string from __PRETTY_FUNCTION__.
void ParseFunctionName(char const *const raw_function_name,
                       string_stuff::String &destination);

} // namespace log_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_LOG_LOGGER_H_
