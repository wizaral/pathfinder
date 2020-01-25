#include "libmx.h"

static void sort(uint8_t *left, uint8_t *right, size_t bytes,
int (*cmp)(const void *, const void *)) {
    uint8_t *i = left;
    uint8_t *j = right;
    size_t temp1 = (right - left) / bytes;
    size_t temp2 = temp1 / 2;
    uint8_t pivot[bytes];

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

void mx_sort(void *arr, size_t size, size_t bytes,
int (*cmp)(const void *, const void *)) {
    if (arr && size > 1 && bytes > 0 && cmp)
        sort(arr, (uint8_t *)arr + ((size - 1) * bytes), bytes, cmp);
}
