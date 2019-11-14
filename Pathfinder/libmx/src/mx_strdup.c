#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *ptr = mx_strnew(mx_strlen(s1));
    return ptr ? mx_strcpy(ptr, s1) : NULL;
}
