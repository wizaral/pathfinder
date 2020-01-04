#include "libmx.h"

static inline void swap(void *arr, size_t *i, size_t *j, size_t bytes) {
    mx_swap((t_byte *)arr + *i, (t_byte *)arr + *j, bytes);
    *i += bytes;
    *j -= bytes;
}

void mx_quicksort_rec(void *arr, size_t size, size_t bytes,
    long long (*w)(const void *)) {
    if (arr && size > 0 && bytes > 0 && w) {
        size_t i = 0;
        size_t j = (size - 1) * bytes;
        t_byte temp[bytes];
        long long pivot = w(mx_memcpy(temp,
        ((t_byte *)arr + (size / 2) * bytes), bytes));

        while (i < j) {
            for (; w((t_byte *)arr + i) < pivot; i += bytes);
            for (; w((t_byte *)arr + j) > pivot; j -= bytes);
            if (i <= j)
                swap(arr, &i, &j, bytes);
        }

        if (i / bytes < size - 1)
            mx_quicksort_rec((t_byte *)arr + i, size - i / bytes, bytes, w);
        if (0 < j / bytes)
            mx_quicksort_rec(arr, j / bytes + 1, bytes, w);
    }
}
