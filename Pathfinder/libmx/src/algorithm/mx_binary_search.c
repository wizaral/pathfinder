#include "libmx.h"

t_ll mx_binary_search(const void *key, const void *arr, const size_t size,
    const size_t bytes, int (*cmp)(const void *, const void *))
{
    t_ll left = 0;
    t_ll right = size - 1;
    t_ll middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (cmp(key, arr + middle * bytes) == 0)
            return middle;
        else if (cmp(key, arr + middle * bytes) > 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
