#include "suite.hpp"

template <typename T>
auto max(T lhs, T rhs) -> T {
    return lhs < rhs ? rhs : lhs;
};

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

auto main(int argc, char** argv) -> int {
    auto s = setup(argc, argv);
    defer(cleanup(s));
    auto maybe_idx = boyer_moore_horspool_search(s.haystack, s.needle);
    assert(maybe_idx.exists);
    printf("Found %s at index %d\n", s.needle.ptr, maybe_idx.value);
}
