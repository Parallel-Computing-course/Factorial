#include "singlethread_factorial.h"

unsigned long long singlethread_factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}
