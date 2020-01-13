#include "libmx.h"

t_u64 mx_sqrt_natural(t_u64 x) {
    t_u64 left = 0;
    t_u64 right = 4294967295;
    t_u64 middle = 0;
    t_u64 power;

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
