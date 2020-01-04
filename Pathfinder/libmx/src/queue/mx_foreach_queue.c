#include "libmx.h"

void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && f) {
        size_t byte = q->bytes;
        size_t endt = q->tail * byte;
        size_t endc = q->cap * byte;

        if (q->head <= q->tail)
            for (size_t i = q->head * byte; i <= endt; i += byte)
                f((t_byte *)q->arr + i);
        else {
            for (size_t i = q->head * byte; i < endc; i += byte)
                f((t_byte *)q->arr + i);
            for (size_t i = 0; i <= endt; i += byte)
                f((t_byte *)q->arr + i);
        }
    }
}
