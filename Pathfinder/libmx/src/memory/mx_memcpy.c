#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *udst = dst;
    const unsigned char *usrc = src;

    for (size_t i = 0; i < n; udst[i] = usrc[i], ++i);
    return (void *)dst;
}
