#include "libmx.h"

void *mx_front(t_queue *q) {
    return q && q->arr ? (t_byte *)q->arr + (q->head * q->bytes) : NULL;
}
