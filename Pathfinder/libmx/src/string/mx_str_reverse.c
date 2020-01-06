#include "libmx.h"

void mx_str_reverse(char *s) {
    if (s) {
        t_i64 j = mx_strlen(s) - 1;

        for (t_i64 i = 0; i < j; ++i, --j)
            mx_swap(s + i, s + j, sizeof(char));
    }
}
