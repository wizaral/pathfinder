#include "libmx.h"

void *mx_at(t_vector *v, size_t pos) {
    return v && v->arr && pos < v->size
    ? (t_byte *)v->arr + (v->bytes * pos)
    : NULL;
}
