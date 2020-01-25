#include "libmx.h"

size_t mx_strlen(const char *s) {
    size_t len = 0;

    for (; s[len]; ++len);
    return len;
}
