#include "libmx.h"

t_queue *mx_create_queue(size_t bytes) {
    t_queue *queue = bytes > 0 ? (t_queue *)malloc(sizeof(t_queue)) : NULL;

    if (queue) {
        queue->bytes = bytes;
        queue->cap = 32;

        queue->head = queue->tail = queue->size = 0;
        queue->arr = malloc(bytes * queue->cap);
    }
    return queue;
}
