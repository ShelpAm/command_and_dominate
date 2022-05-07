#include "small_utility/utility/utility.h"

#include <cstdio>

using namespace small_utility;

int main() {
  utility::Sleep(3000);
  if (utility::Equal(1,2)) { return 2; }
  if (utility::Unequal(true, true)) { return 3; }

  return 0;
}
