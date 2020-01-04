#include "libmx.h"

void mx_str_reverse(char *s) {
    if (s) {
        unsigned long long j = mx_strlen(s) - 1;

        for (unsigned long long i = 0; i < j; ++i, --j)
            mx_swap(s + i, s + j, sizeof(char));
    }
}
