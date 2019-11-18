#include "libmx.h"

int mx_sqrt(int x) {
    unsigned long long left = 0;
    unsigned long long right = x > 0 ? x : 0;
    unsigned long long middle = 0;
    unsigned long long pow;

    while (left <= right) {
        middle = left + (right - left) / 2;
        pow = middle * middle;

        if (pow == (unsigned long long)x)
            return middle;
        else if (pow > (unsigned long long)x)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return 0;
}
