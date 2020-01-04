#include "libmx.h"

unsigned long long mx_factorial(unsigned long long n) {
    unsigned long long result = 1;

    if (n > 20)
        return 0;
    for (unsigned long long i = 1; i <= n; ++i)
        result *= i;
    return result;
}
