#pragma once
#include "defer.hpp"
#include "types.hpp"
#include <cassert>
#include <cstdio>
#include <cstdlib>

auto read_entire_file(const char *path) -> String {
  assert(path);
  auto handle = fopen(path, "r");
  assert(handle);
  defer(fclose(handle));
  fseek(handle, 0, SEEK_END);
  auto buffer_size = ftell(handle);
  auto buffer = (char *)malloc(buffer_size);
  rewind(handle);
  fread(buffer, sizeof(char), buffer_size, handle);
  return String{
      .ptr = buffer,
      .len = (int)buffer_size,
  };
}
