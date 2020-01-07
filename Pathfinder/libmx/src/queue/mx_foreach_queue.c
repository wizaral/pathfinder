#include "libmx.h"

void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && q->size && f) {
        t_byte *starth = q->arr + q->head * q->bytes;
        t_byte *endt = q->arr + (q->tail + 1) * q->bytes;
        t_byte *endc = q->arr + q->cap * q->bytes;

        if (q->head <= q->tail)
            for (; starth < endt; starth += q->bytes)
                f(starth);
        else {
            for (; starth < endc; starth += q->bytes)
                f(starth);
            for (t_byte *i = q->arr; i < endt; i += q->bytes)
                f(i);
        }
    }
}
