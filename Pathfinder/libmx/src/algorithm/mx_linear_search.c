#include "libmx.h"

t_byte *mx_linear_search(const void *key, t_vector *v,
    int (*cmp)(const void *, const void *)) {
    t_byte *end = v->arr + (v->size - 1) * v->bytes;

    for (t_byte *i = v->arr; i < end; i += v->bytes)
        if (cmp(key, i) == 0)
            return i;
    return NULL;
}
