#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    for (; *s; ++s)
        if (*s == c)
            return (char *)s;
    return NULL;
}
