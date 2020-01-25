#include "libmx.h"

void mx_reverse_vector(t_vector *v) {
    if (v && v->size && v->arr) {
        size_t i = 0;
        size_t j = (v->size - 1) * v->bytes;

        for (size_t b = v->bytes; i < j; i += b, j -= b)
            mx_swap(v->arr + i, v->arr + j, b);
    }
}
