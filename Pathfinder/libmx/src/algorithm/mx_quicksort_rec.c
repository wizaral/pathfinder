#include "libmx.h"

static void sort(t_byte *left, t_byte *right, size_t bytes,
    long long (*w)(const void *)) {
    t_byte *i = left;
    t_byte *j = right;
    t_byte temp[bytes];
    long long pivot = w(mx_memcpy(temp, left + (right - left) / 2, bytes));

    while (i < j) {
        for (; w(i) < pivot; i += bytes);
        for (; w(j) > pivot; j -= bytes);
        if (i <= j) {
            mx_swap(i, j, bytes);
            i += bytes;
            j -= bytes;
        }
    }
    if (left < j)
        sort(left, j, bytes, w);
    if (i < right)
        sort(i, right, bytes, w);
}

void mx_quicksort_rec(void *arr, size_t size, size_t bytes,
    long long (*w)(const void *)) {
    if (arr && size > 1 && bytes > 0 && w)
        sort(arr, (t_byte *)arr + (size - 1) * bytes, bytes, w);
}
