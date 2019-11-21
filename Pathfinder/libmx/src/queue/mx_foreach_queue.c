#include "libmx.h"

// переделать для очереди с замкнутым массивом
void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && f)
        for (t_ull i = 0; i < q->size; ++i)
            f((t_uc *)q->arr + (q->bytes * i));
}
