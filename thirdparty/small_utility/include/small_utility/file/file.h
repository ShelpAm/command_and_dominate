// Copyright 2022 small_sheep_

#ifndef SMALL_UTILITY_FILE_FILE_H_
#define SMALL_UTILITY_FILE_FILE_H_

#include "small_utility/file/file_forward.h"
#include <cstdio>

namespace small_utility {

namespace file_stuff {

class File {
 public:
  explicit File(char const *const file_name, bool const truncate = false);
  ~File();

  // Prints something to file.
  int Print(char const *const content) const;

 private:
  int Open(char const *const file_name, bool const truncate);
  int Close() const;

  FILE* file_ptr_;
};

void MakeDirectory(char const *const path_name);
void Remove(char const *const path_name);

}  // namespace file_stuff

}  // namespace small_utility

#endif  // SMALL_UTILITY_FILE_FILE_H_
