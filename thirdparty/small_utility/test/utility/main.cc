#include "small_utility/utility/utility.h"

#include <cstdio>

using namespace small_utility;

int main() {
  utility_stuff::Sleep(3000);
  if (utility_stuff::Equal(1,2)) { return 2; }
  if (utility_stuff::Unequal(true, true)) { return 3; }

  return 0;
}
