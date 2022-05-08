#include "small_utility/log/logger.h"
#include <map>
#include "small_utility/file/file.h"
#include "small_utility/string/string.h"
#include "small_utility/time/time.h"
#include "small_utility/utility/utility.h"

namespace small_utility {

namespace log_stuff {

Logger &Logger::Instance() {
  static Logger logger;
  return logger;
}

void Logger::AddLogMessageInfo(LogMessageInfo const &log_message_info) {
  log_message_infos_.push_back(log_message_info);
}

// TODO(small_sheep_ 1178550325@qq.com): This Method should be expanded and
//                                       abstacted.
void Logger::WriteToTarget(char const *const target) {
  if (utility::Equal(target, "console")) {
    for (auto const &i : log_message_infos_) {
      if (i.log_level >= log_level_minimum_) {
        printf(i.message.CStr());
      }
    }
  } else {
    file_stuff::FilePointer file_pointer(new file_stuff::File(target));
    for (auto const &i : log_message_infos_) {
      if (i.log_level >= log_level_minimum_) {
        file_pointer->Print(i.message.CStr());
      }
    }
  }
}

#undef Debug(...)
#undef Info(...)
#undef Warn(...)
#undef Error(...)
#undef Fatal(...)

void Logger::Debug(char const *const pattern,
                   string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  LogMessageInfo log_message_info;
  log_message_info.log_level = LogLevel::kLogLevelDebug;
  ProcessLogMessage(pattern, message, line, file_name, function_name,
                    log_message_info.log_level, log_message_info.message);
  AddLogMessageInfo(log_message_info);
}
void Logger::Debug(string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  Debug(PatternDefault().CStr(), message, line, file_name, function_name);
}

void Logger::Info(char const *const pattern,
                  string_stuff::String const &message, int const line,
                  char const *const file_name,
                  char const *const function_name) {
  LogMessageInfo log_message_info;
  log_message_info.log_level = LogLevel::kLogLevelInfo;
  ProcessLogMessage(pattern, message, line, file_name, function_name,
                    log_message_info.log_level, log_message_info.message);
  AddLogMessageInfo(log_message_info);
}

void Logger::Info(string_stuff::String const &message, int const line,
                  char const *const file_name,
                  char const *const function_name) {
  Info(PatternDefault().CStr(), message, line, file_name, function_name);
}

void Logger::Warn(char const *const pattern,
                  string_stuff::String const &message, int const line,
                  char const *const file_name,
                  char const *const function_name) {
  LogMessageInfo log_message_info;
  log_message_info.log_level = LogLevel::kLogLevelWarn;
  ProcessLogMessage(pattern, message, line, file_name, function_name,
                    log_message_info.log_level, log_message_info.message);
  AddLogMessageInfo(log_message_info);
}

void Logger::Warn(string_stuff::String const &message, int const line,
                  char const *const file_name,
                  char const *const function_name) {
  Warn(PatternDefault().CStr(), message, line, file_name, function_name);
}

void Logger::Error(char const *const pattern,
                   string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  LogMessageInfo log_message_info;
  log_message_info.log_level = LogLevel::kLogLevelError;
  ProcessLogMessage(pattern, message, line, file_name, function_name,
                    log_message_info.log_level, log_message_info.message);
  AddLogMessageInfo(log_message_info);
}

void Logger::Error(string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  Error(PatternDefault().CStr(), message, line, file_name, function_name);
}

void Logger::Fatal(char const *const pattern,
                   string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  LogMessageInfo log_message_info;
  log_message_info.log_level = LogLevel::kLogLevelFatal;
  ProcessLogMessage(pattern, message, line, file_name, function_name,
                    log_message_info.log_level, log_message_info.message);
  AddLogMessageInfo(log_message_info);
}

void Logger::Fatal(string_stuff::String const &message, int const line,
                   char const *const file_name,
                   char const *const function_name) {
  Fatal(PatternDefault().CStr(), message, line, file_name, function_name);
}

int ProcessLogMessage(
    string_stuff::String const &pattern, string_stuff::String const &message,
    int const line, char const *const file_name,
    char const *const function_name, LogLevel const log_level,
    string_stuff::String &log_message) {
  // Replaces patterns with true string.
  log_message = pattern;
  string_stuff::String function_name_real;
  ParseFunctionName(function_name, function_name_real);
  log_message.Replace("$(content)", message.CStr());
  log_message.Replace("$(line)", string_stuff::String(line).CStr());
  log_message.Replace("$(file_name)", file_name);
  log_message.Replace("$(function_name)", function_name_real.CStr());
  log_message.Replace(
      "$(time)",
      string_stuff::String(
          time_stuff::Time().SetToCurrentTime(),
          "$(year)-$(month)-$(day) $(hour):$(minute):$(second)").CStr());
  log_message.Replace("$(log_level)", string_stuff::String(log_level).CStr());


  // --------DEPRECATED--------
  /*std::map<string_stuff::String, string_stuff::String> pattern_map;
  pattern_map["content"] = string_stuff::String(content);
  pattern_map["line"] = string_stuff::String(line);
  pattern_map["file_name"] = string_stuff::String(file_name);
  ParseFunctionName(function_name, pattern_map["function_name"]);
  pattern_map["time"] =
    string_stuff::String(time_stuff::Time().SetToCurrentTime(),
                         "$(year)-$(month)-$(day) $(hour):$(minute):$(second)");
  pattern_map["log_level"] = string_stuff::String(log_level);
  std::map<string_stuff::String, string_stuff::String>::iterator it;

  for (int i = 0; i != pattern_string.Size(); ) {
    int left_position = pattern_string.Find("$(", i);
    if (utility::Equal(left_position, -1)) {
      log_message += pattern_string.SubStringIndex(i, pattern_string.Size()-1);
      break;
    }
    int right_position = pattern_string.Find(")", left_position);
    if (utility::Equal(right_position, -1)) {
      log_message += pattern_string.SubStringIndex(left_position + 2,
                                                   pattern_string.Size() - 1);
      break;
    }
    if (left_position > i) {
      log_message += pattern_string.SubStringIndex(i, left_position - 1);
    }
    i = right_position + 1;
    buffer_string = pattern_string.SubStringIndex(left_position + 2,
                                                  right_position - 1);
    it = pattern_map.find(buffer_string);
    buffer_string = utility::Equal(it, pattern_map.end()) ?  "" : (*it).second;
    log_message += buffer_string;
  }
  */

  return 0;
}

void ParseFunctionName(char const *const raw_function_name,
                       string_stuff::String &destiniation) {
  string_stuff::String source_function_name(raw_function_name);
  destiniation = source_function_name.SubStringIndex(
      source_function_name.Find(' ') + 1, source_function_name.Size() - 1);
}

}  // namespace log_stuff

}  // namespace small_utility
