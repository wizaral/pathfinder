#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    t_byte *udst = dst;
    const t_byte *usrc = src;

    for (size_t i = 0; i < n; ++i)
        udst[i] = usrc[i];
    return (void *)dst;
}
