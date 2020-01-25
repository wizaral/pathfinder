#include "libmx.h"

void mx_delete_queue(t_queue *q) {
    if (q) {
        if (MX_MALLOC_SIZE(q->arr))
            free(q->arr);
        if (MX_MALLOC_SIZE(q))
            free(q);
    }
}
