#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *us = (void *)s;

    for (size_t i = 0; us && i < n; ++i)
        if (us[i] == c)
            return (void *)(us + i);
    return NULL;
}
