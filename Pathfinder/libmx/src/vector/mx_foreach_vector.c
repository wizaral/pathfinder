#include "libmx.h"

void mx_foreach_vector(t_vector *v, void (*f)(void *)) {
    if (v && v->arr && f) {
        t_byte *end = v->arr + v->size * v->bytes;

        for (t_byte *i = v->arr; i < end; i += v->bytes)
            f(i);
    }
}
