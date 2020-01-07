#include "libmx.h"

bool mx_checksort(const void *arr, size_t size, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp) {
        t_byte *end = (t_byte *)arr + (size - 1) * bytes;

        for (const t_byte *i = arr; i < end; i += bytes)
            if (cmp(i, i + bytes) > 0)
                return false;
        return true;
    }
    return false;
}
