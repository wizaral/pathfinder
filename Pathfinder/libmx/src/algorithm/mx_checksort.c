#include "libmx.h"

bool mx_checksort(const void *arr, size_t size, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp) {
        size_t end = (size - 1) * bytes;

        for (size_t i = 0; i < end; i += bytes)
            if (cmp((t_byte *)arr + i, (t_byte *)arr + (i + bytes)) > 0)
                return false;
        return true;
    }
    return false;
}
