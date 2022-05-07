#ifndef SMALL_UTILITY_TIME_TIME_H_
#define SMALL_UTILITY_TIME_TIME_H_

#include <ctime>
#include <time.h>
#include "small_utility/macro/macro.h"

namespace small_utility {

namespace time_stuff {

class Time {
 public:
  Time();
  Time(int const year, int const month, int const day, int const hour,
       int const minute, int const second, int const millisecond);
  Time(tm const &t);
  Time(tm const *t);
  Time(Time const &t);
  Time &operator=(tm const *t);

#if defined SMALL_UTILITY_LINUX
#define SetToCurrentTime() SetToCurrentTimeLinux()
  Time const &SetToCurrentTimeLinux();
#elif defined SMALL_UTILITY_WINDOWS
#define SetToCurrentTime() SetToCurrentTimeWindows()
  Time const &SetToCurrentTimeWindows();
#endif

  int const Year() const { return year_; }
  int const Month() const { return month_; }
  int const Day() const { return day_; }
  int const Hour() const { return hour_; }
  int const Minute() const { return minute_; }
  int const Second() const { return second_; }
  int const Millisecond() const { return millisecond_; }
 private:
  void Swap(Time &rhs);

  int year_, month_, day_, hour_, minute_, second_, millisecond_;
};

} // namespace time_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_TIME_TIME_H_
