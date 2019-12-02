#include "libmx.h"

void mx_foreach_vector(t_vector *v, void (*f)(void *)) {
    if (v && v->arr && f)
        for (t_ull i = 0; i < v->size; ++i)
            f((t_uc *)v->arr + (v->bytes * i));
}
