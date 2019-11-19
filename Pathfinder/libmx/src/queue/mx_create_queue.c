#include "libmx.h"

t_queue *mx_create_queue(size_t bytes) {
    t_queue *queue = bytes > 0 ? (t_queue *)malloc(sizeof(t_queue)) : NULL;

    if (queue) {
        queue->bytes = bytes;
        queue->capacity = 10;

        queue->pointer1 = 0;
        queue->pointer2 = 0;

        queue->size = 0;
        queue->array = malloc(bytes * queue->capacity);
    }
    return queue;
}
