#include "libmx.h"

void mx_pop_backward(t_vector *v) {
    if (v && v->arr) {
        --v->size;

        if ((float)v->cap / v->size > 4 && v->cap > 32) {
            v->cap /= 2;
            v->arr = mx_realloc(v->arr, v->cap);
        }
    }
}
