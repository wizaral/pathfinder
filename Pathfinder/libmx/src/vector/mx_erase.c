#include "libmx.h"

void mx_erase(t_vector *v, size_t pos) {
    if (v && v->size) {
        if (pos < v->size - 1) {
            t_byte *start = v->arr + (pos + 1) * v->bytes;
            t_byte *end = v->arr + (v->size - 1) * v->bytes;

            for (; start < end; start += v->bytes)
                mx_memcpy(start - v->bytes, start, v->bytes);
        }
        --v->size;
        if ((float)v->cap / v->size > 4.0f && v->cap > VECTOR_DEFAULT_SIZE) {
            v->cap /= 2;
            v->arr = mx_realloc(v->arr, v->bytes * v->cap);
        }
    }
}
