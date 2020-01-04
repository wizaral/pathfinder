#include "libmx.h"

void mx_foreach_vector(t_vector *v, void (*f)(void *)) {
    if (v && v->arr && f) {
        size_t end = v->size * v->bytes;

        for (size_t i = 0; i < end; i += v->bytes)
            f((t_byte *)v->arr + i);
    }
}
