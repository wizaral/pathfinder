#include "libmx.h"

static inline void increase_queue(t_queue *q) {
    t_byte *temp_arr = q && q->arr ? malloc(q->bytes * q->cap * 2) : NULL;

    if (temp_arr) {
        if (q->tail < q->head) {
            mx_memcpy(temp_arr, q->arr + q->head * q->bytes,
                (q->cap - q->head + 1) * q->bytes);
            mx_memcpy(temp_arr + (q->cap - q->head) * q->bytes, q->arr,
                (q->tail + 1) * q->bytes);
        }
        else
            mx_memcpy(temp_arr, q->arr, q->cap * q->bytes);
        if (malloc_size(q->arr))
            free(q->arr);
        q->arr = temp_arr;
        q->cap *= 2;
        q->head = 0;
        q->tail = q->size - 1;
    }
}

void mx_enqueue(t_queue *q, void *item) {
    if (q && q->arr && item) {
        if (q->size) {
            if (q->size == q->cap)
                increase_queue(q);
            if (q->tail + 1 == q->cap) {
                mx_memcpy(q->arr, item, q->bytes);
                q->tail = 0;
            }
            else {
                mx_memcpy(q->arr + q->tail * q->bytes, item, q->bytes);
                ++q->tail;
            }
        }
        else {
            mx_memcpy(q->arr, item, q->bytes);
            q->head = q->tail = 0;
        }
        ++q->size;
    }
}
