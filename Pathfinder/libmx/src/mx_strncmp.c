#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    const char *end = s1 + n;
    int result = 0;

    if (s1 && s1 == s2)
        return 0;

    for (; !result && s1 != end && (*s1 || *s2); result = *s1++ - *s2++);
    return result;
}
