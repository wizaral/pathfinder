#include "libmx.h"

void mx_foreach_stack(t_stack *st, void (*f)(void *)) {
    if (st && st->arr && f)
        for (t_ull i = 0; i < st->size; ++i)
            f((t_uc *)st->arr + (st->bytes * i));
}
