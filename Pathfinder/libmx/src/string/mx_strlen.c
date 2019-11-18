#include "libmx.h"

int mx_strlen(const char *s) {
    int len = 0;

    for (; s[len]; ++len);
    return len;
}
