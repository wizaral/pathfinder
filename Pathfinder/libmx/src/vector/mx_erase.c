#include "libmx.h"

void mx_erase(t_vector *v, size_t pos) {
    if (v) {
        if (pos < v->size - 1) {
            for (size_t i = pos + 1; i < v->size; ++i)
                mx_memcpy((t_byte *)v->arr + (i - 1) * v->bytes,
                    (t_byte *)v->arr + i * v->bytes,
                    v->bytes);
        }
        --v->size;
        if ((float)v->cap / v->size > 4 && v->cap > VECTOR_DEFAULT_SIZE) {
            v->cap /= 2;
            v->arr = mx_realloc(v->arr, v->bytes * v->cap);
        }
    }
}
