#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *udst = dst;
    const unsigned char *usrc = src;

    if (dst && src)
        for (size_t i = 0; i < n; ++i) {
            udst[i] = usrc[i];

            if (usrc[i] == c)
                return (void *)(udst + i + 1);
        }
    return NULL;
}
