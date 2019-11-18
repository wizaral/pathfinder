#include "libmx.h"

void mx_str_reverse(char *s) {
    for (int i = 0, j = s ? mx_strlen(s) - 1 : 0; s && i < j; ++i, --j)
        mx_swap_char(s + i, s + j);
}
