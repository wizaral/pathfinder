#include "libmx.h"

// переделать для очереди с замкнутым массивом
void *mx_rear(t_queue *queue) {
    return queue && queue->array ? (unsigned char)queue->array : NULL;
}
