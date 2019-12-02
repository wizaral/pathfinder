#include "libmx.h"

void mx_insert(t_vector *v, t_ull pos, const void *item) {
    if (v && item) {
        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, v->cap);
        }

        if (pos < v->size) {
            for (t_ull i = pos + 1; i < v->size; ++i)
                mx_memcpy((t_uc *)v->arr + (i - 1) * v->bytes,
                    (t_uc *)v->arr + i * v->bytes,
                    v->bytes);
        }
        --v->size;
    }
}
