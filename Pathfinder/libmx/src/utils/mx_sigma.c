#include "libmx.h"

static unsigned long long sigma(unsigned long long n, unsigned long long acc) {
    return n == 1 ? acc + 1 : sigma(n - 1, acc + n);
}

unsigned long long mx_sigma(unsigned long long n) {
    return n > 6074000999 ? 0 : sigma(n, 0);
}
