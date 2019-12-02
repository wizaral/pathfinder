#include "libmx.h"

t_vector *mx_create_vector(size_t bytes) {
    t_vector *v = bytes > 0 ? (t_vector *)malloc(sizeof(t_vector)) : NULL;

    if (v) {
        v->cap = 32;
        v->size = 0;
        v->bytes = bytes;
        v->arr = malloc(bytes * v->cap);
    }
    return v;
}
