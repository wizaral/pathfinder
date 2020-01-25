#include "libmx.h"

char *mx_strndup(const char *str, size_t n) {
    size_t len = mx_strlen(str);
    size_t min = MX_MIN(len, n, size_t);
    char *ptr = mx_strnew(min);

    return ptr ? mx_strncpy(ptr, str, min) : NULL;
}
