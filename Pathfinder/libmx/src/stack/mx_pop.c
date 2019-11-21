#include "libmx.h"

void *mx_pop(t_stack *st) {
    void *item = mx_top(st);

    if (st && st->arr) {
        --st->size;

        if ((float)st->cap / st->size > 3 && st->cap > 30) {
            st->cap = st->cap / 3 + 1;
            st->arr = mx_realloc(st->arr, st->cap);
        }
    }
    return item;
}
