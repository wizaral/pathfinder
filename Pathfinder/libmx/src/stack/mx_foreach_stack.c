#include "libmx.h"

void mx_foreach_stack(t_stack *st, void (*f)(void *)) {
    if (st && st->arr && f) {
        t_byte *end = st->arr + st->size * st->bytes;

        for (t_byte *i = st->arr; i < end; i += st->bytes)
            f(i);
    }
}
