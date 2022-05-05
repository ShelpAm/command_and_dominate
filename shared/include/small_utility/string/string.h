// Copyright 2022 small_sheep_

#ifndef SMALL_UTILITY_SRC_STRING_STRING_H_
#define SMALL_UTILITY_SRC_STRING_STRING_H_

#include "small_utility/time/time_forward.h"
#include "small_utility/log/log_level.h"

namespace small_utility {

namespace string_stuff {

class String {
 private:
  using Iterator = char *;
  using ConstIterator = char const *;

 public:
  String(char const *const rhs = "");

  // The padding argument is for snprintf.
  explicit String(int const integer, char const *const padding = "00");
  explicit String(log_stuff::LogLevel const log_level);
  String(time_stuff::Time const &time, char const *const pattern);
  String(String const &rhs);
  String &operator=(String rhs);
  String &operator=(char const *const rhs);
  String &operator+=(char const c);
  String &operator+=(char const *const str);
  String &operator+=(String const &s);
  ~String();

  char &operator[](int const index);
  char operator[](int const  index) const;

  void Swap(String &rhs);
  void PushBack(char const c);
  void Append(char const *const str);

  void Reserve(int const size);
  // Resizes the data_.
  //  If size is less than size_, the data from data_[size] will be truncated.
  //  If size is larger than size_, the extra room will be filled with c.
  void Resize(int const size, char c = '\0');

  //  Inserts a char $(c) at $(position). After calling this function,
  //  this->data_[position] will be 'c'.
  void Insert(char const c, int const position);
  void Insert(char const *const str, int const position);

  //  Erases some characters, and fill them with the after characters.
  //  $(position) - starting index
  void Erase(int const position, int const length);
  void Clear();

  int Find(char const c, int const position = 0) const;
  int Find(char const *const str, int const position = 0) const;
  int Replace(char const from, char const to, int const position = 0);
  int Replace(char const *const from, char const *const to,
              int const position = 0);

  String SubStringLength(int const left, int const length) const;
  String SubStringIndex(int const left, int const right) const;

  Iterator Begin() const { return data_; }
  Iterator End() const { return data_ + size_; }

  char const *CStr() const { return data_; }
  char const *ConstData() const { return data_; }
  char *Data() { return data_; }
  int Length() const { return size_; }
  int Size() const { return size_; }
  int Capacity() const { return capacity_; }

 private:
  char *data_;
  int size_;
  int capacity_;
};

String const operator+(String const &lhs, String const &rhs);
String const operator+(String const &lhs, char const *const rhs);
String const operator+(char const *const lhs, String const &rhs);
bool operator<(char const *constlhs, String const &rhs);
bool operator<(String const &lhs, char const *const rhs);
bool operator<(String const &lhs, String const &rhs);
bool operator>(char const *const lhs, String const &rhs);
bool operator>(String const &lhs, char const *const rhs);
bool operator>(String const &lhs, String const &rhs);
bool operator==(char const *const lhs, String const &rhs);
bool operator==(String const &lhs, char const *constrhs);
bool operator==(String const &lhs, String const &rhs);
bool operator!=(char const *const lhs, String const &rhs);
bool operator!=(String const &lhs, char const *constrhs);
bool operator!=(String const &lhs, String const &rhs);

void Print(String const &s);

}  // namespace string_stuff

}  // namespace small_utility

#endif  // SMALL_UTILITY_SRC_STRING_STRING_H_
