#include "libmx.h"

char *mx_strdup(const char *str) {
    char *ptr = mx_strnew(mx_strlen(str));
    return ptr ? mx_strcpy(ptr, str) : NULL;
}
