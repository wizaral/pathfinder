#include "libmx.h"

t_u64 mx_atoull(const char *str) {
    t_u64 sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+')
        ++str;
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sum;
}
