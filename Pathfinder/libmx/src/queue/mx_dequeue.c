#include "libmx.h"

void *mx_dequeue(t_queue *queue) {
    void *item = mx_peek(queue);

    if (queue && queue->array) {
        --queue->size;

        if ((float)queue->capacity / queue->size > 3 && queue->capacity > 30) {
            queue->capacity = queue->capacity / 3 + 1;
            queue->array = mx_realloc(queue->array, queue->capacity);
        }
    }
    return item;
}
