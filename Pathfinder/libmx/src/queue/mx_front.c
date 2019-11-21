#include "libmx.h"

void *mx_front(t_queue *q) {
    return q && q->arr ? (t_uc *)q->arr + (q->tail * q->bytes) : NULL;
}
