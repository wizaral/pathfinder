#include "libmx.h"

t_ll mx_linear_search(void *arr, void *item, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    for (t_ll i = 0; i < size; ++i)
        if (cmp(item, arr + i * bytes) == 0)
            return i;
    return -1;
}
