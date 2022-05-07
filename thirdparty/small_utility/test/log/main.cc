#include "small_utility/file/file.h"
#include "small_utility/log/logger.h"
#include "small_utility/string/string.h"

using namespace small_utility;

int main() {
  log_stuff::Logger::Instance().SetPatternDefault(
      "[$(time)] $(log_level) $(file_name):$(line) in function"
      " '$(function_name)': $(content)\n");
  log_stuff::Logger::Instance().SetLogLevelMinimum(
      log_stuff::LogLevel::kLogLevelInfo);

  string_stuff::String buffer;
  //for (int i = 0; i != 10000; ++i) {
    //buffer = "times:" + string_stuff::String(i);
    //log_stuff::Info("times: " + string_stuff::String(i));
    log_stuff::Debug("wtf debug");
    log_stuff::Info("Info");
    log_stuff::Error("Test error");
    log_stuff::Fatal("Fatal! test");
    log_stuff::Warn("Warn test");
  //}

  log_stuff::Logger::Instance().WriteToTarget("console");
  file_stuff::MakeDirectory("temp");
  log_stuff::Logger::Instance().WriteToTarget("temp/temp_log");

  return 0;
}
