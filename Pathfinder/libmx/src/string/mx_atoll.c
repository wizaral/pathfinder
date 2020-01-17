#include "libmx.h"

t_i64 mx_atoll(const char *str) {
    bool sign = 0;
    t_i64 sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+' || *str == '-')
        sign = *str++ == '-';
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sign ? -sum : sum;
}
