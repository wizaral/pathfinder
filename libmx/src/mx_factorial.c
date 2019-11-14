#include "libmx.h"

static unsigned long long fact(unsigned long long n, unsigned long long acc) {
    return n == 0 ? acc : fact(n - 1, acc * n);
}

unsigned long long mx_factorial(unsigned long long n) {
    return n > 20 ? 0 : (n < 2 ? 1 : fact(n, 1));
}
