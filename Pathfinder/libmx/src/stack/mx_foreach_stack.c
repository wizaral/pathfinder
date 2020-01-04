#include "libmx.h"

void mx_foreach_stack(t_stack *st, void (*f)(void *)) {
    if (st && st->arr && f) {
        size_t end = st->size * st->bytes;
        for (size_t i = 0; i < end; i += st->bytes)
            f((t_byte *)st->arr + i);
    }
}
