#include "libmx.h"

#include <stdio.h>

static void sort(t_byte *left, t_byte *right, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    t_byte *i = left;
    t_byte *j = right;
    t_byte pivot[bytes];

    printf("r-l: %zu r-l/b: %zu r-l/b/2: %zu r-l/b/2*b: %zu\n", right - left, (right - left) / bytes, (right - left) / bytes / 2, (((right - left) / bytes) / 2) * bytes);
    mx_memcpy(pivot, left + ((((right - left) / bytes) / 2) * bytes), bytes);
    // t_vector *v = (t_vector *)pivot;

    // printf("pivot: %zu %zu %zu\n", v->bytes, v->cap, v->size);

    // for (size_t k = 0; k < v->size; ++k)
    //     printf("%zu, ", *(size_t *)mx_at(v, k));
    // printf("\n");

    // printf("1: %p %p\n", (void *)i, (void *)j);

    while (i < j) {
        for (; cmp(i, pivot) < 0; i += bytes);
        for (; cmp(j, pivot) > 0; j -= bytes);
        if (i <= j) {
            mx_swap(i, j, bytes);
            i += bytes;
            j -= bytes;
        }
    }

    // printf("2: %p %p\n", (void *)i, (void *)j);

    if (left < j)
        sort(left, j, bytes, cmp);
    if (i < right)
        sort(i, right, bytes, cmp);
}

void mx_sort_rec(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    if (arr && size > 1 && bytes > 0 && cmp) {
        printf("size: %zu bytes: %zu\n", size, bytes);
        // printf("size: %zu bytes: %zu\n", size, bytes);
        sort(arr, (t_byte *)arr + ((size - 1) * bytes), bytes, cmp);
    }
}
