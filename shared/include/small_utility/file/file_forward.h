// Copyright 2022 small_sheep_

#ifndef SMALL_UTILITY_FILE_FILE_FORWARD_H
#define SMALL_UTILITY_FILE_FILE_FORWARD_H

#include "small_utility/reference_counting/reference_counted_pointer.h"

namespace small_utility {

namespace file_stuff {

class File;
using FilePointer = reference_counting::ReferenceCountedPointer<File>;

}  // namespace file_stuff

}  // namespace small_utility

#endif  // SMALL_UTILITY_FILE_FILE_FORWARD_H
