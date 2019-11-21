#include "libmx.h"

void mx_realloc_queue(t_queue *q, double scale) {
    void *temp_arr = NULL;

    if (q && q->arr) {
        temp_arr = malloc(q->bytes * q->cap * scale);

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
        q->cap *= scale;
        q->head = 0;
        q->tail = q->size - 1;
    }
}
