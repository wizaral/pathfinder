#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    int result = 0;

    if (s1 != s2) {
        const t_byte *us1 = s1;
        const t_byte *us2 = s2;
        const t_byte *end = us1 + n;

        for (; !result && us1 != end; result = *us1++ - *us2++);
    }
    return result;
}
