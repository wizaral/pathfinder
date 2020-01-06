#include "libmx.h"

// #include <stdio.h>

void mx_sort_rec(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp){
        size_t i = 0;
        size_t j = (size - 1) * bytes;
        t_byte pivot[bytes];

        // printf("INSIDE1: %lli %lli %d %lli\n", i / bytes, size - 1, 0, j / bytes);

        mx_memcpy(pivot, ((t_byte *)arr + (size / 2) * bytes), bytes);
        while (i < j) {
            for (; cmp((t_byte *)arr + i, pivot) < 0; i += bytes);
            // printf("for1 %lli %lli\n", i, i / bytes);
            for (; cmp((t_byte *)arr + j, pivot) > 0; j -= bytes);
            //         printf("for2 %lli %lli\n", j, j / bytes);
            // printf("INSIDE2: %lli %lli %d %lli\n", i / bytes, size - 1, 0, j / bytes);
            if (i <= j){
                mx_swap((t_byte *)arr + i, (t_byte *)arr + j, bytes);
                i += bytes;
                j -= bytes;
            }
        }
        // printf("INSIDE3: %lli %lli %d %lli\n", i / bytes, size - 1, 0, j / bytes);
        if (i / bytes < size - 1){
            // printf("================1 %lli\n", size - i / bytes);
            mx_sort((t_byte *)arr + i, size - i / bytes, bytes, cmp);
        }
        if (0 < j / bytes){
            // printf("================2 %lli\n", j / bytes + 1);
            mx_sort_rec(arr, j / bytes + 1, bytes, cmp);
        }
    }
}
