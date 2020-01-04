#include "libmx.h"

void *mx_memdup(const void *src, size_t n) {
    t_byte *udst = (t_byte *)malloc(n);
    const t_byte *usrc = src;

    for (size_t i = 0; i < n; ++i)
        udst[i] = usrc[i];
    return udst;
}
