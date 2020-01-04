#include "libmx.h"

void mx_clear_vector(t_vector *v) {
    if (v && v->size) {
        v->cap = VECTOR_DEFAULT_SIZE;
        v->size = 0;
        if (malloc_size(v->arr))
            free(v->arr);
        v->arr = malloc(v->bytes * VECTOR_DEFAULT_SIZE);
    }
}
