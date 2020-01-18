#include "libmx.h"

static void sort(uint8_t *left, uint8_t *right, size_t bytes,
int64_t (*wgt)(const void *)) {
    uint8_t *i = left;
    uint8_t *j = right;
    uint8_t temp1[bytes];
    size_t temp2 = (right - left) / bytes;
    int64_t pivot = wgt(mx_memcpy(temp1, left + temp2 / 2 * bytes, bytes));

    while (i < j) {
        for (; wgt(i) < pivot; i += bytes);
        for (; wgt(j) > pivot; j -= bytes);
        if (i <= j) {
            mx_swap(i, j, bytes);
            i += bytes;
            j -= bytes;
        }
    }
    if (left < j)
        sort(left, j, bytes, wgt);
    if (i < right)
        sort(i, right, bytes, wgt);
}

void mx_quicksort(void *arr, size_t size, size_t bytes,
int64_t (*wgt)(const void *)) {
    if (arr && size > 1 && bytes > 0 && wgt)
        sort(arr, (uint8_t *)arr + (size - 1) * bytes, bytes, wgt);
}
