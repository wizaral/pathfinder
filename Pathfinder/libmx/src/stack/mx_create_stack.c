#include "libmx.h"

t_stack *mx_create_stack(size_t bytes) {
    t_stack *st = bytes > 0 ? (t_stack *)malloc(sizeof(t_stack)) : NULL;

    if (st) {
        st->cap = STACK_DEFAULT_SIZE;
        st->size = 0;
        st->bytes = bytes;
        st->arr = malloc(bytes * STACK_DEFAULT_SIZE);
    }
    return st;
}
