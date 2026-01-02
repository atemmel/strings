#include <cmath>
#include <cstdio>

#include "suite.hpp"
#pragma comment(lib, "pthread")

template <typename T>
auto min(T lhs, T rhs) -> T {
    return lhs < rhs ? lhs : rhs;
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

auto do_nothing() -> void {
}

struct ThreadContext {
    Mutex* mutex;
    Optional<int>* found_idx;
    String haystack;
    String needle;
    int haystack_offset;
};

auto threaded_search_thread(ThreadContext ctx) -> void {
    auto result = linear_search(ctx.haystack, ctx.needle);
    if (!result.exists) {
        return;
    }

    ctx.mutex->lock();
    defer(ctx.mutex->unlock());
    if (!ctx.found_idx->exists) {
        *ctx.found_idx = Optional<int>::of(result.value + ctx.haystack_offset);
    }
}

auto threaded_search(String haystack, String needle) -> Optional<int> {
    auto n_threads        = Thread::hardware_concurrency();
    auto bytes_per_thread = (int)ceilf((float)haystack.len / (float)n_threads);
    auto threads          = List<Thread>{};
    auto mutex            = Mutex{};
    auto found_idx        = Optional<int>::empty();

    for (int i = 0; i < n_threads; i++) {
        auto first_byte = i * bytes_per_thread;
        auto last_byte  = min(haystack.len, (i + 1) * bytes_per_thread);
        auto byte_slice = haystack.slice(first_byte, last_byte);
        auto ctx        = ThreadContext{
                   .mutex           = &mutex,
                   .found_idx       = &found_idx,
                   .haystack        = byte_slice,
                   .needle          = needle,
                   .haystack_offset = first_byte,
        };
        threads.push_back(Thread(&threaded_search_thread, ctx));
    }
    fprintf(stderr, "Supports %d threads\nBytes: %d\nBytes per thread: %d\n",
            n_threads, haystack.len, bytes_per_thread);

    for (int i = 0; i < n_threads; i++) {
        threads[i].join();
    }
    return found_idx;
};

auto main(int argc, char** argv) -> int {
    auto s = setup(argc, argv);
    defer(cleanup(s));
    auto maybe_idx = threaded_search(s.haystack, s.needle);
    assert(maybe_idx.exists);
    printf("Found %s at index %d\n", s.needle.ptr, maybe_idx.value);
}
