#include "libmx.h"

void mx_delete_stack(t_stack **st) {
    if (st && *st) {
        if (malloc_size((*st)->arr))
            free((*st)->arr);
        if (malloc_size(*st))
            free(*st);
        *st = NULL;
    }
}
