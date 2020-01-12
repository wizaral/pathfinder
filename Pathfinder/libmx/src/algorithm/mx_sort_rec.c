#include "libmx.h"

static void sort(t_byte *left, t_byte *right, size_t bytes,
int (*cmp)(const void *, const void *)) {
    t_byte *i = left;
    t_byte *j = right;
    size_t temp1 = (right - left) / bytes;
    size_t temp2 = temp1 / 2;
    t_byte pivot[bytes];

    mx_memcpy(pivot, left + temp2 * bytes, bytes);
    while (i < j) {
        for (; cmp(i, pivot) < 0; i += bytes);
        for (; cmp(j, pivot) > 0; j -= bytes);
        if (i <= j) {
            mx_swap(i, j, bytes);
            i += bytes;
            j -= bytes;
        }
    }
    if (left < j)
        sort(left, j, bytes, cmp);
    if (i < right)
        sort(i, right, bytes, cmp);
}

void mx_sort_rec(void *arr, size_t size, size_t bytes,
int (*cmp)(const void *, const void *)) {
    if (arr && size > 1 && bytes > 0 && cmp)
        sort(arr, (t_byte *)arr + ((size - 1) * bytes), bytes, cmp);
}
