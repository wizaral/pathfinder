#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    uint8_t *ptr = b;

    for (size_t i = 0; i < len; ++i)
        ptr[i] = c;
    return b;
}
