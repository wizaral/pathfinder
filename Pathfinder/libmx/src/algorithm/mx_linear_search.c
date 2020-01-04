#include "libmx.h"

size_t mx_linear_search(const void *key, t_vector *v,
    int (*cmp)(const void *, const void *)) {
    size_t bytes = v->bytes;
    size_t end = (v->size - 1) * bytes;

    for (size_t i = 0; i < end; i += bytes)
        if (cmp(key, (t_byte *)v->arr + i) == 0)
            return i;
    return 0;
}
