#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    if (s && n) {
        const t_byte *us = s;

        for (size_t i = 0; i < n; ++i)
            if (us[i] == c)
                return (void *)(us + i);
    }
    return NULL;
}
