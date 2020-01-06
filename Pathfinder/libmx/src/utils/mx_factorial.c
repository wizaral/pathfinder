#include "libmx.h"

t_i64 mx_factorial(t_i64 n) {
    t_i64 result = 1;

    if (n > 20)
        return 0;
    for (t_i64 i = 1; i <= n; ++i)
        result *= i;
    return result;
}
