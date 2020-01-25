#include "libmx.h"

void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && q->size && f) {
        uint8_t *starth = q->arr + q->head * q->bytes;
        uint8_t *endt = q->arr + (q->tail + 1) * q->bytes;

        if (q->head <= q->tail)
            for (; starth < endt; starth += q->bytes)
                f(starth);
        else {
            uint8_t *endc = q->arr + q->cap * q->bytes;

            for (; starth < endc; starth += q->bytes)
                f(starth);
            for (uint8_t *i = q->arr; i < endt; i += q->bytes)
                f(i);
        }
    }
}
