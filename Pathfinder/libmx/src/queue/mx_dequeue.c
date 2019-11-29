#include "libmx.h"

static void reduce_queue(t_queue *q) {
    void *temp_arr = NULL;

    if (q && q->arr) {
        temp_arr = malloc(q->bytes * q->cap / 2);

        if (q->tail >= q->head) {
            mx_memcpy(temp_arr,
            (t_uc *)q->arr + q->head * q->bytes,
            q->cap * q->bytes);
        }
        else {
            mx_memcpy(temp_arr,
            (t_uc *)q->arr + q->head * q->bytes,
            (q->cap - q->head + 1) * q->bytes);

            mx_memcpy((t_uc *)temp_arr + (q->cap - q->head + 1) * q->bytes,
            q->arr,
            (q->tail + 1) * q->bytes);
        }

        free(q->arr);
        q->arr = temp_arr;
        q->cap /= 2;
        q->head = 0;
        q->tail = q->size - 1;
    }
}

void *mx_dequeue(t_queue *q) {
    void *item = mx_front(q);

    if (q && q->arr) {
        q->head = q->head + 1 == q->cap ? 0 : q->head + 1;
        --q->size;

        if ((float)q->cap / q->size > 4 && q->cap > 32)
            reduce_queue(q);
    }
    return item;
}
