#include "multithread_factorial.h"
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;
unsigned long long result_multithread = 1;

void partial_factorial(int start, int end) {
    unsigned long long local_result = 1;
    for (int i = start; i <= end; ++i) {
        local_result *= i;
    }
    std::lock_guard<std::mutex> lock(mtx);
    result_multithread *= local_result;
}

unsigned long long multithread_factorial(int num, int thread_count) {
    result_multithread = 1;
    std::vector<std::thread> threads;
    int chunk_size = num / thread_count;
    int remainder = num % thread_count;

    int start = 1;
    for (int i = 0; i < thread_count; ++i) {
        int end = start + chunk_size - 1 + (i < remainder ? 1 : 0);
        threads.emplace_back(partial_factorial, start, end);
        start = end + 1;
    }

    for (auto& th : threads) {
        th.join();
    }

    return result_multithread;
}
