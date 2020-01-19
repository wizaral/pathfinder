#include "libmx.h"

void mx_clear_stack(t_stack *st) {
    if (st && st->size) {
        st->cap = STACK_DEFAULT_SIZE;
        st->size = 0;
        if (MX_MALLOC_SIZE(st->arr))
            free(st->arr);
        st->arr = malloc(st->bytes * STACK_DEFAULT_SIZE);
    }
}
