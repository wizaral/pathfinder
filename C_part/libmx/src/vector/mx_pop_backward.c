#include "libmx.h"

void mx_pop_backward(t_vector *v) {
    if (v && v->arr) {
        --v->size;
        if ((float)v->cap / v->size > 4 && v->cap > VECTOR_DEFAULT_SIZE) {
            v->cap /= 2;
            v->arr = mx_realloc(v->arr, v->bytes * v->cap);
        }
    }
}
