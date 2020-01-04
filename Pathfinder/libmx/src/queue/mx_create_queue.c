#include "libmx.h"

t_queue *mx_create_queue(size_t bytes) {
    t_queue *q = bytes > 0 ? (t_queue *)malloc(sizeof(t_queue)) : NULL;

    if (q) {
        q->cap = QUEUE_DEFAULT_SIZE;
        q->head = q->tail = q->size = 0;
        q->bytes = bytes;
        q->arr = malloc(bytes * QUEUE_DEFAULT_SIZE);
    }
    return q;
}
