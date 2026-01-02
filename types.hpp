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

  auto slice(int from) const -> String { return slice(from, len); }

  auto slice(int from, int to) const -> String {
    assert(from >= 0);
    assert(from <= len);
    assert(to >= 0);
    assert(to <= len);
    assert(from <= to);
    return String{
        .ptr = ptr + from,
        .len = to - from,
    };
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
