#include "libmx.h"

t_vector *mx_create_vector(size_t size, size_t bytes) {
    t_vector *v = bytes > 0 ? (t_vector *)malloc(sizeof(t_vector)) : NULL;

    if (v) {
        size_t capacity = VECTOR_DEFAULT_SIZE;

        for (; capacity < SIZE_MAX; capacity *= 2)
            if (capacity > size)
                break;
        v->cap = capacity;
        v->size = size;
        v->bytes = bytes;
        v->arr = malloc(bytes * capacity);
    }
    return v;
}
