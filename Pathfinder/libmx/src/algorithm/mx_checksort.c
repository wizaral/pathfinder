#include "libmx.h"

bool mx_checksort(const void *arr, const size_t size, const size_t bytes,
    int (*cmp)(const void *, const void *))
{
    t_ull end = size * bytes;

    if (arr && size > 0 && bytes > 0 && cmp) {
        for (t_ull i = 0, j = bytes; j < end; i += bytes, j += bytes)
            if (cmp((t_uc *)arr + i, (t_uc *)arr + j) > 0)
                return false;
        return true;
    }
    return false;
}
