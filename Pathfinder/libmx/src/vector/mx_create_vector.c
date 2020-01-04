#include "libmx.h"

t_vector *mx_create_vector(size_t size, size_t bytes) {
    t_vector *v = bytes > 0 ? (t_vector *)malloc(sizeof(t_vector)) : NULL;

    if (v) {
        v->cap = VECTOR_DEFAULT_SIZE;
        v->size = size;
        v->bytes = bytes;
        v->arr = malloc(bytes * VECTOR_DEFAULT_SIZE);
    }
    return v;
}
