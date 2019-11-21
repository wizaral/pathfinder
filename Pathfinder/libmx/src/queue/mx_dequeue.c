#include "libmx.h"

void *mx_dequeue(t_queue *q) {
    void *item = mx_front(q);

    if (q && q->arr) {
        q->head = q->head + 1 == q->cap ? 0 : q->head + 1;
        --q->size;

        if ((float)q->cap / q->size > 3 && q->cap > 20)
            mx_realloc_queue(q, 0.5);
    }
    return item;
}
