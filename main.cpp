#include "io.hpp"
#include "types.hpp"
#include <cstdio>
#include <cstdlib>

template <typename T> auto max(T lhs, T rhs) -> T {
  return lhs < rhs ? rhs : lhs;
};

auto linear_search(String haystack, String needle) -> Optional<int> {
  for (int i = 0; i < haystack.len; i++) {
    for (int j = 0; j < needle.len && i + j < haystack.len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
      if (j + 1 == needle.len) {
        return Optional<int>::of(i);
      }
    }
  }
  return Optional<int>::empty();
}

auto boyer_moore_horspool_search(String haystack, String needle)
    -> Optional<int> {
  int skip_table[256];
  int skip = 0;

  for (int i = 0; i < 256; i++) {
    skip_table[i] = -1;
  }
  for (int i = 0; i < needle.len - 1; i++) {
    skip_table[needle[i]] = i;
  }

  while (skip <= haystack.len - needle.len) {
    int j = needle.len - 1;
    while (j >= 0 && needle[j] == haystack[skip + j]) {
      j--;
    }
    if (j < 0) {
      return Optional<int>::of(skip);
    } else {
      skip += max(1, j - skip_table[haystack[skip + j]]);
    }
  }
  return Optional<int>::empty();
}

auto main(int argc, const char **argv) -> int {
  if (argc <= 1) {
    printf("No filename passed, exiting...\n");
    exit(1);
  }

  auto path = argv[1];

  auto src = read_entire_file(path);
  defer(free(src.ptr));

  auto needle = String::of((char *)"afternoon");

  {
    auto maybe_idx = linear_search(src, needle);
    assert(maybe_idx.exists);
    printf("Found %s at index %d\n", needle.ptr, maybe_idx.value);
  }

  {
    auto maybe_idx = boyer_moore_horspool_search(src, needle);
    assert(maybe_idx.exists);
    printf("Found %s at index %d\n", needle.ptr, maybe_idx.value);
  }
}
