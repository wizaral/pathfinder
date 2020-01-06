#include "libmx.h"

t_i64 mx_sqrt_natural(t_i64 x) {
    t_i64 left = 0;
    t_i64 right = 4294967295;
    t_i64 middle = 0;
    t_i64 power;

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
