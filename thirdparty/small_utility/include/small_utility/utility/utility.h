#ifndef SMALL_UTILITY_UTILITY_UTILITY_H_
#define SMALL_UTILITY_UTILITY_UTILITY_H_

#include <cstdio>
#include <cstring>
#include "small_utility/macro/macro.h"
#if defined SMALL_UTILITY_LINUX
# include <time.h>
#elif defined SMALL_UTILITY_WINDOWS
# include <windows.h>
#endif // _WIN32

namespace small_utility {

namespace utility_stuff {

#if defined SMALL_UTILITY_LINUX

#define Sleep(time)                     SleepLinux(time)
#define Popen(command, type)            PopenLinux(command, type)
#define Pclose(file_ptr)                PcloseLinux(file_ptr)

#elif defined SMALL_UTILITY_WINDOWS

#define Sleep(time)                     SleepWindows(time)
#define Popen(command, type)            PopenWindows(command, type)
#define Pclose(file_ptr)                PcloseWindows(file_ptr)

#endif

// The unit of this function is millisecond.
void SleepLinux (int const time);
void SleepWindows (int const time);

FILE *PopenLinux(char const *command, char const *type);
FILE *PopenWindows(char const *command, char const *type);
int const PcloseLinux(FILE* file_ptr);
int const PcloseWindows(FILE* file_ptr);

template<typename type>
inline void Swap(type &lhs, type &rhs) {
  type temp(lhs);
  lhs = rhs;
  rhs = temp;
}

// Provide an interface, which is to decide if the to object is equal.
template<typename TLeft, typename TRight>
inline bool Equal(TLeft const &lhs, TRight const &rhs) {
  return lhs == rhs;
}

inline bool Equal(char const *const lhs, char const *const rhs) {
  return !strcmp(lhs, rhs);
}

// Provide an interface, which is to decide if the to object is Unequal.
template<typename left_type, typename right_type>
inline bool Unequal(left_type const &lhs, right_type const &rhs) {
  return lhs != rhs;
}

template<typename left_type, typename right_type>
inline bool operator!=(left_type const &lhs, right_type const &rhs) {
  return !(lhs == rhs);
}

template<typename type>
inline type operator+(type const &lhs, type const &rhs) {
  return type(lhs) += rhs;
}

} // namespace utility_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_UTILITY_UTILITY_H_
