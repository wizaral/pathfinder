#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    uint8_t *udst = dst;
    const uint8_t *usrc = src;

    for (size_t i = 0; i < n; ++i)
        udst[i] = usrc[i];
    return (void *)dst;
}
