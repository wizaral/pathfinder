#include "libmx.h"

void mx_foreach_stack(t_stack *st, void (*f)(void *)) {
    if (st && st->arr && f) {
        uint8_t *end = st->arr + st->size * st->bytes;

        for (uint8_t *i = st->arr; i < end; i += st->bytes)
            f(i);
    }
}
