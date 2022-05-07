#include "small_utility/file/file.h"

#include <cstdio>

using small_utility::file_stuff::File;
using small_utility::file_stuff::FilePointer;

int main() {
  File *const file_ptr(new File("temporary_file1.tmp"));
  FilePointer file_pointer(file_ptr);

  return file_pointer->Print("test123\n");
}
