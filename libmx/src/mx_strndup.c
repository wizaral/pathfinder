#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_min_ll(n, mx_strlen(s1));
    char *s2 = s1 ? mx_strnew(len) : NULL;

    return s2 ? mx_strncpy(s2, s1, len) : NULL;
}
