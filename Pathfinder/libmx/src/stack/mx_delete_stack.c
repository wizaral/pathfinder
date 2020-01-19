#include "libmx.h"

void mx_delete_stack(t_stack *st) {
    if (st) {
        if (MX_MALLOC_SIZE(st->arr))
            free(st->arr);
        if (MX_MALLOC_SIZE(st))
            free(st);
    }
}
