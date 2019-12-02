#include "libmx.h"

void mx_clear(t_vector *v) {
    if (v && v->size) {
        v->cap = 32;
        v->size = 0;
        free(v->arr);
        v->arr = malloc(v->bytes * v->cap);
    }
}
