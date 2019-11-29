#include "libmx.h"

// переделать для очереди с замкнутым массивом
void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && f) {
        if (q->head <= q->tail)
            for (t_ull i = q->head; i < q->size; ++i)
                f((t_uc *)q->arr + (q->bytes * i));
        else {
            for (t_ull i = q->head; i < q->cap; ++i)
                f((t_uc *)q->arr + (q->bytes * i));
            for (t_ull i = 0; i <= q->tail; ++i)
                f((t_uc *)q->arr + (q->bytes * i));
        }
    }
}
