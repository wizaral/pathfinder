#include "libmx.h"

t_u64 mx_factorial(t_u64 n) {
    t_u64 result = 1;

    if (n > 20)
        return 0;
    for (t_u64 i = 1; i <= n; ++i)
        result *= i;
    return result;
}
