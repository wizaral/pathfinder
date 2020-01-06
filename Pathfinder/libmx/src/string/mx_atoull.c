#include "libmx.h"

t_i64 mx_atoull(const char *str) {
    t_i64 sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+')
        ++str;
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sum;
}
