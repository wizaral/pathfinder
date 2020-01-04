#include "libmx.h"

unsigned long long mx_sqrt_natural(unsigned long long x) {
    unsigned long long left = 0;
    unsigned long long right = 4294967295;
    unsigned long long middle = 0;
    unsigned long long power;

    while (left <= right) {
        middle = left + (right - left) / 2;
        power = middle * middle;
        if (power > x)
            right = middle - 1;
        else if (power < x)
            left = middle + 1;
        else
            return middle;
    }
    return 0;
}
