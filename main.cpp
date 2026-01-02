#include "io.hpp"
#include "types.hpp"
#include <cstdio>
#include <cstdlib>

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

auto main(int argc, const char **argv) -> int {
  if (argc <= 1) {
    printf("No file name passed, exiting...\n");
    exit(1);
  }

  auto path = argv[1];

  auto src = read_entire_file(path);
  defer(free(src.ptr));

  auto needle = String::of((char *)"afternoon");

  auto maybe_idx = linear_search(src, needle);

  assert(maybe_idx.exists);
  printf("Found %s at index %d\n", needle.ptr, maybe_idx.value);
}
