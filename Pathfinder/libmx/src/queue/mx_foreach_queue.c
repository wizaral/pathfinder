#include "libmx.h"

// переделать для очереди с замкнутым массивом
void mx_foreach_queue(t_queue *queue, void (*f)(void *)) {
    if (queue && queue->array && f)
        for (long long i = 0; i < queue->size; ++i)
            f((unsigned char)queue->array + (queue->bytes * i));
}
