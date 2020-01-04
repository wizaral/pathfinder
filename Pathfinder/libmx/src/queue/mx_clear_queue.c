#include "libmx.h"

void mx_clear_queue(t_queue *q) {
    if (q && q->size) {
        q->cap = QUEUE_DEFAULT_SIZE;
        q->size = q->head = q->tail = 0;
        if (malloc_size(q->arr))
            free(q->arr);
        q->arr = malloc(q->bytes * QUEUE_DEFAULT_SIZE);
    }
}
