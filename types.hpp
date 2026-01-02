#pragma once

#include <cassert>
#include <cstring>

struct String {

  static auto of(char *ptr) -> String {
    assert(ptr);
    return {
        .ptr = ptr,
        .len = (int)strlen(ptr),
    };
  }

  auto operator[](int idx) const -> char {
    assert(idx >= 0);
    assert(idx < len);
    return ptr[idx];
  }

  char *ptr;
  int len;
};

template <typename T> struct Optional {
  static auto of(T value) -> Optional<T> {
    return {
        .value = value,
        .exists = true,
    };
  };

  static auto empty() -> Optional<T> {
    return {
        .exists = false,
    };
  }

  const T value;
  const bool exists;
};
