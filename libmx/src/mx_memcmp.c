#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *us1 = (void *)s1;
    unsigned char *us2 = (void *)s2;
    unsigned char *end = us1 + n;
    int result = 0;

    if (s1 == s2)
        return 0;

    for (; !result && us1 != end; result = *us1++ - *us2++);
    return result;
}
