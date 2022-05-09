#include "small_utility/time/time.h"
#include "small_utility/macro/macro.h"
#include "small_utility/utility/utility.h"

namespace small_utility {

namespace time_stuff {

Time::Time() : year_(0), month_(0), day_(0), hour_(0),
               minute_(0), second_(0), millisecond_(0) {}

Time::Time(int const year, int const month, int const day, int const hour,
           int const minute, int const second, int const millisecond)
    : year_(year), month_(month), day_(day), hour_(hour),
      minute_(minute), second_(second), millisecond_(millisecond) {}

Time::Time(tm const &t)
    : year_(t.tm_year + 1900), month_(t.tm_mon + 1), day_(t.tm_mday),
      hour_(t.tm_hour), minute_(t.tm_min), second_(t.tm_sec), millisecond_(0) {}

Time::Time(tm const *t)
    : year_(t->tm_year + 1900), month_(t->tm_mon + 1), day_(t->tm_mday),
      hour_(t->tm_hour), minute_(t->tm_min), second_(t->tm_sec),
      millisecond_(0) {}

Time::Time(Time const &t)
    : year_(t.Year()), month_(t.Month()), day_(t.Day()), hour_(t.Hour()),
      minute_(t.Minute()), second_(t.Second()), millisecond_(t.Millisecond()) {}

Time &Time::operator=(tm const *t) {
  Time temp(t);
  Swap(temp);
  return *this;
}

#if defined SMALL_UTILITY_LINUX
Time const &Time::SetToCurrentTimeLinux() {
  timespec t;
  int err = clock_gettime(CLOCK_REALTIME_ALARM, &t);
  if (err) {}// TODO(small_sheep_ 1178550325@qq.com): Need to handle the error.
  *this = localtime(&t.tv_sec);
  millisecond_ = t.tv_nsec / 1e6;
  return *this;
}
#elif defined SMALL_UTILITY_WINDOWS
  Time const &Time::SetToCurrentTimeWindows() {
    //TODO(small_sheep_ 1178550325@qq.com) please finish this function
    return Time();
  }
#endif

void Time::Swap(Time &rhs) {
  utility_stuff::Swap(*this, rhs);
}

} // namespace time_stuff

} // namespace small_utility
