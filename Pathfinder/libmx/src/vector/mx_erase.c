#include "libmx.h"

void mx_erase(t_vector *v, t_ull pos) {
    if (v) {
        if (pos < v->size - 1)
            for (t_ull i = pos + 1; i < v->size; ++i)
                mx_memcpy((t_uc *)v->arr + (i - 1) * v->bytes,
                    (t_uc *)v->arr + i * v->bytes,
                    v->bytes);
        --v->size;

        if ((float)v->cap / v->size > 4 && v->cap > 32) {
            v->cap /= 2;
            v->arr = mx_realloc(v->arr, v->cap);
        }
    }
}
