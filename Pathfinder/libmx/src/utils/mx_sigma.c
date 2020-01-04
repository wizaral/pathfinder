#include "libmx.h"

unsigned long long mx_sigma(unsigned long long n) {
    unsigned long long result = 0;

    if (n < 6074001000)
        for (unsigned long long i = 1; i <= n; ++i)
            result += i;
    return result;
}
