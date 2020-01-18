#include "libmx.h"

uint8_t *mx_lsearch(const void *key, t_vector *v,
int (*cmp)(const void *, const void *)) {
    uint8_t *end = v->arr + v->size * v->bytes;

    for (uint8_t *i = v->arr; i < end; i += v->bytes)
        if (cmp(key, i) == 0)
            return i;
    return NULL;
}
