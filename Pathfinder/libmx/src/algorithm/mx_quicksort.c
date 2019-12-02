#include "libmx.h"

void mx_quicksort(void *arr, const size_t size, const size_t bytes,
    int (*cmp)(const void *, const void *))
{
    t_ull i = 0;
    t_ull j = (size - 1) * bytes;
    t_uc x[bytes];

    if (arr && size > 0 && bytes > 0 && cmp) {
        mx_memcpy(x, ((t_uc *)arr + (size / 2) * bytes), bytes);

        while (i < j) {
            for (; cmp((t_uc *)arr + i, x) < 0; i += bytes);
            for (; cmp((t_uc *)arr + j, x) > 0; j -= bytes);
            if (i <= j) {
                mx_swap((t_uc *)arr + i, (t_uc *)arr + j, bytes);
                i += bytes, j -= bytes;
            }
        }
        if (i / bytes < size - 1)
            mx_quicksort((t_uc *)arr + i, size - i / bytes, bytes, cmp);
        if (0 < j / bytes)
            mx_quicksort(arr, j / bytes + 1, bytes, cmp);
    }
}
