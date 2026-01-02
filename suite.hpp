#pragma once

#include "defer.hpp"
#include "types.hpp"
#include <cstdio>
#include <cstdlib>

struct Setup {
  String haystack;
  String needle;
};

static auto read_entire_file(const char *path) -> String {
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

auto setup(int argc, char **argv) -> Setup {
  if (argc <= 1) {
    printf("No filename passed, exiting...\n");
    exit(1);
  }
  if (argc <= 2) {
    printf("No pattern passed, exiting...\n");
    exit(1);
  }
  if (argc > 3) {
    printf("Too many arguments passed, exiting...\n");
    exit(1);
  }

  auto path = argv[1];
  auto needle = argv[2];
  auto haystack = read_entire_file(path);

  return {
      .haystack = haystack,
      .needle = String::of(needle),
  };
}

auto cleanup(Setup setup) -> void { free(setup.haystack.ptr); }
