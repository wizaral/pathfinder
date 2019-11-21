#include "libmx.h"

void mx_enqueue(t_queue *q, void *item) {
    if (q && q->arr && item && q->size) {
        if (q->size == q->cap)
            mx_realloc_queue(q, 2);

        if (q->tail + 1 == q->cap) {
            mx_memcpy((t_uc *)q->arr, item, q->bytes);
            q->tail = 0;
        }
        else {
            mx_memcpy((t_uc *)q->arr + ++q->tail * q->bytes,
            item,
            q->bytes);
        }
        ++q->size;
    }
    else if (q && q->arr && item) {
        mx_memcpy(q->arr, item, q->bytes);
        ++q->size;
    }
}
