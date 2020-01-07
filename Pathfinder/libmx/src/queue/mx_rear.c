#include "libmx.h"

void *mx_rear(t_queue *q) {
    return q && q->arr ? q->arr + (q->tail * q->bytes) : NULL;
}
