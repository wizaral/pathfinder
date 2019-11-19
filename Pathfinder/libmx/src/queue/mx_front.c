#include "libmx.h"

// переделать для очереди с замкнутым массивом
void *mx_front(t_queue *queue) {
    return queue && queue->array ?
        (unsigned char)queue->array + (queue->bytes * (queue->size - 1)) :
        NULL;
}
