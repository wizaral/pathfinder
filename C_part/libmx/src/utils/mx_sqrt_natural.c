#include "libmx.h"

uint64_t mx_sqrt_natural(uint64_t x) {
    uint64_t left = 0;
    uint64_t right = 4294967295;
    uint64_t middle = 0;
    uint64_t power;

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
