#include "suite.hpp"

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

auto main(int argc, char** argv) -> int {
    auto s = setup(argc, argv);
    defer(cleanup(s));
    auto maybe_idx = linear_search(s.haystack, s.needle);
    assert(maybe_idx.exists);
    printf("Found %s at index %d\n", s.needle.ptr, maybe_idx.value);
}
