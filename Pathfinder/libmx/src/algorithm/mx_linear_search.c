#include "libmx.h"

t_ll mx_linear_search(const void *key, const void *arr, const size_t size,
    const size_t bytes, int (*cmp)(const void *, const void *))
{
    for (t_ll i = 0; i < size; ++i)
        if (cmp(key, arr + i * bytes) == 0)
            return i;
    return -1;
}
