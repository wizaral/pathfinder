#include "libmx.h"

void *mx_top(t_stack *st) {
    return st && st->arr && st->size
    ? st->arr + (st->bytes * (st->size - 1))
    : NULL;
}
