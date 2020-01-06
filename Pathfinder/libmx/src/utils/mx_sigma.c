#include "libmx.h"

t_i64 mx_sigma(t_i64 n) {
    t_i64 result = 0;

    if (n < 6074001000)
        for (t_i64 i = 1; i <= n; ++i)
            result += i;
    return result;
}
