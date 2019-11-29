#include "libmx.h"

static void increase_queue(t_queue *q) {
    void *temp_arr = NULL;

    if (q && q->arr) {
        temp_arr = malloc(q->bytes * q->cap * 2);

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
        q->cap *= 2;
        q->head = 0;
        q->tail = q->size - 1;
    }
}

void mx_enqueue(t_queue *q, void *item) {
    if (q && q->arr && item && q->size) {
        if (q->size == q->cap)
            mx_realloc_queue(q, 2);

        if (q->tail + 1 == q->cap) {
            mx_memcpy((t_uc *)q->arr, item, q->bytes);
            q->tail = 0;
        }
        else {
            mx_memcpy((t_uc *)q->arr + ++q->tail * q->bytes,
            item,
            q->bytes);
        }
        ++q->size;
    }
    else if (q && q->arr && item) {
        mx_memcpy(q->arr, item, q->bytes);
        ++q->size;
    }
}
