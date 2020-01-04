#include "libmx.h"

void mx_insert(t_vector *v, size_t pos, const void *item) {
    if (v && item && pos <= v->size) {
        size_t b = v->bytes;

        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, b * v->cap);
        }
        if (pos < v->size) {
            for (size_t i = v->size * b; i > pos + b; i -= b)
                mx_memcpy((t_byte *)v->arr + i, (t_byte *)v->arr + i - b, b);
        }
        mx_memcpy((t_byte *)v->arr + pos * b, item, b);
        ++v->size;
    }
}
