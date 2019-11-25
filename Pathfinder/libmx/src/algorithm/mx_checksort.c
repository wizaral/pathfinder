#include "libmx.h"

bool mx_checksort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    t_ull end = size * bytes;

    if (arr && size > 0 && bytes > 0 && cmp) {
        for (t_ull i = 0, j = bytes; j < end; i += bytes, j += bytes)
            if (cmp(arr + i, arr + j) > 0)
                return false;
        return true;
    }
    return false;
}
