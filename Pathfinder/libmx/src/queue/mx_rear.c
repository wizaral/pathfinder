#include "libmx.h"

void *mx_rear(t_queue *q) {
    return q && q->arr ? (t_uc *)q->arr + (q->head * q->bytes) : NULL;
}
