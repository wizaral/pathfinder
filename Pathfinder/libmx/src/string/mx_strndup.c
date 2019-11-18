#include "libmx.h"

char *mx_strndup(const char *str, size_t n) {
    size_t len = mx_min_ll(n, mx_strlen(str));
    char *ptr = str ? mx_strnew(len) : NULL;

    return ptr ? mx_strncpy(ptr, str, len) : NULL;
}
