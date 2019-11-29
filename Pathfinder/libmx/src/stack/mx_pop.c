#include "libmx.h"

void *mx_pop(t_stack *st) {
    void *item = mx_top(st);

    if (st && st->arr) {
        --st->size;

        if ((float)st->cap / st->size > 4 && st->cap > 32) {
            st->cap /= 2;
            st->arr = mx_realloc(st->arr, st->cap);
        }
    }
    return item;
}
