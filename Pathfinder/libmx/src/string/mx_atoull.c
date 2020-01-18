#include "libmx.h"

uint64_t mx_atoull(const char *str) {
    uint64_t sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+')
        ++str;
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sum;
}
