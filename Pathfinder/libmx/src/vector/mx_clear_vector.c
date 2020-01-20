#include "libmx.h"

void mx_clear_vector(t_vector *v) {
    if (v && v->size) {
        v->cap = VECTOR_DEFAULT_SIZE;
        v->size = 0;
        if (v->size > VECTOR_DEFAULT_SIZE * 64) {
            if (MX_MALLOC_SIZE(v->arr))
                free(v->arr);
            v->arr = malloc(v->bytes * VECTOR_DEFAULT_SIZE);
        }
    }
}
