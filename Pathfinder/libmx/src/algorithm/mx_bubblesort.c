#include "libmx.h"

void mx_bubblesort(void *arr, const size_t size, const size_t bytes,
    int (*cmp)(const void *, const void *))
{
    for (t_ll i = 0, swaps = 0; arr && i < size; ++i, swaps = 0) {
        for (t_ll j = 0; j < size - i - 1; ++j)
            if (cmp(arr + j * size, arr + (j + 1) * size) > 0)
                mx_swap_copy(arr + j, arr + j + 1, bytes), ++swaps;
        if (swaps == 0)
            break;
    }
}
