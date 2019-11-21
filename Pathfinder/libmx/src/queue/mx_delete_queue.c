#include "libmx.h"

void mx_delete_queue(t_queue **q) {
    if (q && *q) {
        if (malloc_size((*q)->arr))
            free((*q)->arr);
        if (malloc_size(*q))
            free(*q);
        *q = NULL;
    }
}
