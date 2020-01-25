#include "libmx.h"

void *mx_front(t_queue *q) {
    return q && q->arr ? q->arr + (q->head * q->bytes) : NULL;
}
