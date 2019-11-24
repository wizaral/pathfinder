#include "libmx.h"

t_ll mx_binary_search(void *arr, void *item, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    t_ll left = 0;
    t_ll right = size - 1;
    t_ll middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (cmp(item, arr + middle * bytes) == 0)
            return middle;
        else if (cmp(item, arr + middle * bytes) > 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
