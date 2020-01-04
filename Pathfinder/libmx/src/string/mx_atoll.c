#include "libmx.h"

long long mx_atoll(const char *str) {
    bool sign = 0;
    long long sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+' || *str == '-')
        sign = *str++ == '-';
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sign ? -sum : sum;
}
