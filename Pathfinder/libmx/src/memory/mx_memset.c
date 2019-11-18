#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ptr = b;

    for (size_t i = 0; i < len; ptr[i] = c, ++i);
    return b;
}
