#include "libmx.h"

void *mx_rear(t_queue *q) {
    return q && q->arr ? (t_byte *)q->arr + (q->tail * q->bytes) : NULL;
}
