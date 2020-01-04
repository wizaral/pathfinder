#include "libmx.h"

void mx_delete_stack(t_stack *st) {
    if (st) {
        if (malloc_size(st->arr))
            free(st->arr);
        if (malloc_size(st))
            free(st);
    }
}
