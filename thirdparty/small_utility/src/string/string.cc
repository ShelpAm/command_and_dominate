// Copyright 2022 small_sheep_

#include "small_utility/string/string.h"

#include <cassert>
#include <cstdio>
#include <cstring>

#include "small_utility/time/time.h"
#include "small_utility/utility/utility.h"

namespace small_utility {

namespace string_stuff {

String::String(char const *const rhs) {
  assert(rhs);
  size_ = strlen(rhs);
  data_ = new char[size_ + 1];
  memcpy(data_, rhs, size_ + 1);
  capacity_ = size_;
}

String::String(int const integer, char const *const padding) : data_(nullptr) {
  char buffer[11];
  String format("%");
  (format += padding) += 'i';
  snprintf(buffer, sizeof(buffer), /*"%i"*/format.ConstData(), integer);
  String temp(buffer);
  Swap(temp);
}

String::String(log_stuff::LogLevel const log_level) : data_(nullptr) {
  String temp;
  switch (log_level) {
    case log_stuff::LogLevel::kLogLevelDebug: temp = "DEBUG"; break;
    case log_stuff::LogLevel::kLogLevelInfo: temp = "INFO"; break;
    case log_stuff::LogLevel::kLogLevelWarn: temp = "WARN"; break;
    case log_stuff::LogLevel::kLogLevelError: temp = "ERROR"; break;
    case log_stuff::LogLevel::kLogLevelFatal: temp = "FATAL"; break;
    default: temp = "INVALID_LOG_LEVEL"; break;
  }
  Swap(temp);
}

String::String(time_stuff::Time const &time, char const *const pattern)
    : data_(nullptr) {
  String string_pattern(pattern);
  string_pattern.Replace("$(year)", String(time.Year(), "04").CStr());
  string_pattern.Replace("$(month)", String(time.Month(), "02").CStr());
  string_pattern.Replace("$(day)", String(time.Day(), "02").CStr());
  string_pattern.Replace("$(hour)", String(time.Hour(), "02").CStr());
  string_pattern.Replace("$(minute)", String(time.Minute(), "02").CStr());
  string_pattern.Replace("$(second)", String(time.Second(), "02").CStr());
  Swap(string_pattern);
}

String::String(String const &rhs) : data_(nullptr) {
  String temp(rhs.ConstData());
  Swap(temp);
}

String &String::operator=(String rhs) {
  Swap(rhs);
  return *this;
}

String &String::operator=(char const *const rhs) {
  String temp(rhs);
  Swap(temp);
  return *this;
}

String &String::operator+=(char const c) {
  PushBack(c);
  return *this;
}

String &String::operator+=(char const *const str) {
  Append(str);
  return *this;
}

String &String::operator+=(String const &s) {
  Append(s.ConstData());
  return *this;
}

String::~String() {
  delete[] data_;
  data_ = nullptr;
}


char &String::operator[](int const index) {
  assert(index >= 0); assert(index < size_);
  return data_[index];
}

char String::operator[](int const index) const {
  assert(index >= 0); assert(index < size_);
  return data_[index];
}

void String::Swap(String &rhs) {
  utility_stuff::Swap(data_, rhs.data_);
  utility_stuff::Swap(size_, rhs.size_);
  utility_stuff::Swap(capacity_, rhs.capacity_);
}

void String::PushBack(char const c) {
  if (utility_stuff::Equal(size_, capacity_)) {
    Reserve(capacity_ ? capacity_ * 2 : 4);
  }
  data_[size_] = c;
  data_[size_ + 1] = '\0';
  ++size_;
}

void String::Append(char const *const str) {
  int const length_str = strlen(str);
  int const  length_add_up = length_str + size_;
  if (length_add_up >= capacity_) {
    Reserve(length_add_up * 2);
  }
  memcpy(data_ + size_, str, length_str);
  data_[length_add_up] = '\0';
  size_ += length_str;
}

void String::Reserve(int const size) {
  if (size <= size_) {
    return;
  }
  char *new_data = new char[size + 1];
  memcpy(new_data, data_, size_);
  delete[] data_;
  data_ = new_data;
  capacity_ = size;
}

void String::Resize(int const size, char c) {
  if (size < size_) {
    data_[size] = '\0';
  } else {
    if (size > capacity_) {
      Reserve(size);
    }
    for (int i = 0; i != size; ++i) {
      data_[i] = c;
    }
    data_[size] = '\0';
  }
  size_ = size;
}

void String::Insert(char const c, int const position) {
  assert(position >= 0 && position <= size_);
  if (utility_stuff::Equal(size_, capacity_)) {
    Reserve(capacity_ ? capacity_ * 2 : 4);
  }
  for (int i = size_ + 1; i != position; --i) {
    data_[i] = data_[i - 1];
  }
  data_[position] = c;
  ++size_;
}

void String::Insert(char const *const str, int const position) {
  assert(position >= 0 && position <= size_);
  int const str_length = strlen(str);
  if (size_ + str_length > capacity_) {
    Reserve(size_ + str_length);
  }
  // make room for Insertee.
  for (int i = size_; i != position - 1; --i) {
    data_[i + str_length] = data_[i];
  }
  memcpy(data_ + position, str, str_length);
  size_ += str_length;
}

void String::Erase(int const position, int const length) {
  assert(position >= 0 && position <= size_);
  assert(length >= 0);
  if (length >= size_ - position + 1) {
    data_[position] = '\0';
    size_ = position;
  } else {
    memcpy(data_ + position, data_ + position + length, size_ - position + 1);
    size_ -= length;
  }
}

void String::Clear() {
  data_[0] = '\0';
  size_ = 0;
}

int String::Find(char const c, int const position) const {
  assert(position >= 0 && position <= size_);
  for (int i = position; i != size_; ++i) {
    if (utility_stuff::Equal(data_[i], c)) {
      return i;
    }
  }
  return -1;
}

int String::Find(char const *const str, int const position) const {
  assert(position >= 0 && position <= size_);
  char const *const sub_str = strstr(data_ + position, str);
  if (sub_str) {
    return sub_str - data_;
  } else {
    return -1;
  }
}

int String::Replace(char const from, char const to, int const position) {
  int pos = Find(from, position);
  if (utility_stuff::Equal(pos, -1)) {
    return -1;
  }
  data_[pos] = position;
  return pos;
}

int String::Replace(char const *const from, char const *const to,
              int const position) {
  int pos = Find(from, position);
  if (utility_stuff::Equal(pos, -1)) {
    return -1;
  }
  //String temp(SubStringLength(0, pos));
  //temp += String(to);
  int position_last = pos + strlen(from);
  String temp(SubStringLength(0, pos));
  (temp += to) += SubStringLength(pos + strlen(from), size_ - position_last);
  Swap(temp);
  return pos;
}

String String::SubStringLength(int const left, int const length) const {
  assert(left >= 0);
  assert(length >= 0);
  assert(left + length <= size_);
  //----DEPRECATED----
  //char *buffer = new char[length + 1];
  //memcpy(buffer, data_ + left, length);
  //buffer[length] = '\0';
  //String return_string(buffer);
  //delete[] buffer;
  String string_return;
  string_return.Reserve(length);
  memcpy(string_return.Data(), data_ + left, length);
  string_return.Data()[length] = '\0';
  string_return.size_ = length;
  return string_return;
}

String String::SubStringIndex(int const left, int const right) const {
  assert(left <= right);
  return SubStringLength(left, right - left + 1);
}

String const operator+(String const &lhs, String const &rhs) {
  return String(lhs) += rhs;
}

String const operator+(char const *const lhs, String const &rhs) {
  return String(lhs) += rhs;
}

String const operator+(String const &lhs, char const *const rhs) {
  return String(lhs) += rhs;
}

bool operator<(char const *const lhs, String const &rhs) {
  return strcmp(lhs, rhs.ConstData()) < 0;
}

bool operator<(String const &lhs, char const *const rhs) {
  return strcmp(lhs.ConstData(), rhs) < 0;
}

bool operator<(String const &lhs, String const &rhs) {
  return strcmp(lhs.ConstData(), rhs.ConstData()) < 0;
}

bool operator>(char const *const lhs, String const &rhs) {
  return strcmp(lhs, rhs.ConstData()) > 0;
}

bool operator>(String const &lhs, char const *const rhs) {
  return strcmp(lhs.ConstData(), rhs) > 0;
}

bool operator>(String const &lhs, String const &rhs) {
  return strcmp(lhs.ConstData(), rhs.ConstData()) > 0;
}

bool operator==(char const *const lhs, String const &rhs) {
  return !strcmp(lhs, rhs.ConstData());
}

bool operator==(String const &lhs, char const *const rhs) {
  return !strcmp(lhs.ConstData(), rhs);
}

bool operator==(String const &lhs, String const &rhs) {
  return !strcmp(lhs.ConstData(), rhs.ConstData());
}

bool operator!=(char const *const lhs, String const &rhs) {
  return strcmp(lhs, rhs.ConstData());
}

bool operator!=(String const &lhs, char const *const rhs) {
  return strcmp(lhs.ConstData(), rhs);
}

bool operator!=(String const &lhs, String const &rhs) {
  return strcmp(lhs.ConstData(), rhs.ConstData());
}

void Print(String const &s) {
  printf("The data_ of string:\"%s\"\n", s.ConstData());
}

}  // namespace string_stuff

}  // namespace small_utility
