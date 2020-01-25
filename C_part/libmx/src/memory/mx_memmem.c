#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const uint8_t *ubig = big;

    if (big_len > little_len && little_len)
        while (big_len >= little_len && mx_memcmp(ubig, little, little_len)) {
            ++ubig;
            --big_len;
        }
    return big_len >= little_len && little_len ? (void *)ubig : NULL;
}
