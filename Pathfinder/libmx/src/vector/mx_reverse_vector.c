#include "libmx.h"

void mx_reverse_vector(t_vector *v) {
    if (v && v->size && v->arr)
        for (t_ull i = 0, j = v->size - 1; i < j; i += v->bytes, j -= v->bytes)
            mx_swap((t_uc *)v->arr + i, (t_uc *)v->arr + j, v->bytes);
}