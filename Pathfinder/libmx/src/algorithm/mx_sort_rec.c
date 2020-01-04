#include "libmx.h"

void mx_sort_rec(void *arr, size_t size, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp) {
        size_t i = 0;
        size_t j = (size - 1) * bytes;
        t_byte pivot[bytes];

        mx_memcpy(pivot, ((t_byte *)arr + (size / 2) * bytes), bytes);
        while (i < j) {
            for (; cmp((t_byte *)arr + i, pivot) < 0; i += bytes);
            for (; cmp((t_byte *)arr + j, pivot) > 0; j -= bytes);
            if (i <= j) {
                mx_swap((t_byte *)arr + i, (t_byte *)arr + j, bytes);
                i += bytes;
                j -= bytes;
            }
        }
        if (i / bytes < size - 1)
            mx_sort_rec((t_byte *)arr + i, size - i / bytes, bytes, cmp);
        if (0 < j / bytes)
            mx_sort_rec(arr, j / bytes + 1, bytes, cmp);
    }
}
