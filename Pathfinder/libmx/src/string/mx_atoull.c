#include "libmx.h"

unsigned long long mx_atoull(const char *str) {
    unsigned long long sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+')
        ++str;
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sum;
}
