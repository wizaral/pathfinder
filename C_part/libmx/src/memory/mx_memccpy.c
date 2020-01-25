#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    if (dst && src && n) {
        uint8_t *udst = dst;
        const uint8_t *usrc = src;

        for (size_t i = 0; i < n; ++i) {
            udst[i] = usrc[i];
            if (usrc[i] == c)
                return (void *)(udst + i + 1);
        }
    }
    return NULL;
}
