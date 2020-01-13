#include "libmx.h"

t_u64 mx_sigma(t_u64 n) {
    t_u64 result = 0;

    if (n < 6074001000)
        for (t_u64 i = 1; i <= n; ++i)
            result += i;
    return result;
}
