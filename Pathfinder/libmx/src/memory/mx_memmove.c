#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    if (len > 0) {
        t_byte temp[len];

        mx_memcpy(temp, src, len);
        mx_memcpy(dst, temp, len);
    }
    return dst;
}
