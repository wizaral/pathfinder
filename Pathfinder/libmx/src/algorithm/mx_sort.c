#include "libmx.h"

static inline void push(t_stack *stack, size_t left, size_t right) {
    mx_push(stack, &right);
    mx_push(stack, &left);
}

static inline void update(t_parametrs *prm, t_byte *pivot, size_t bytes) {
    prm->i = (prm->left = *(size_t *)(mx_pop(&prm->stack))) * bytes;
    prm->j = (prm->right = *(size_t *)(mx_pop(&prm->stack))) * bytes;
    mx_memcpy(pivot, (t_byte *)prm->arr +
    (prm->left + (prm->right - prm->left) / 2) * bytes, bytes);
}

static inline void shrink(t_parametrs *prm, t_byte *pivot, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    for (; cmp((t_byte *)prm->arr + prm->i, pivot) < 0; prm->i += bytes);
    for (; cmp((t_byte *)prm->arr + prm->j, pivot) > 0; prm->j -= bytes);
}

static inline void swap(t_parametrs *prm, size_t bytes) {
    mx_swap((t_byte *)prm->arr + prm->i, (t_byte *)prm->arr + prm->j, bytes);
    prm->i += bytes;
    prm->j -= bytes;
}

void mx_sort(void *arr, size_t size, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp) {
        t_byte pivot[bytes];
        t_parametrs prm = {arr, 0, size - 1, 0, size - 1, {STACK_DEFAULT_SIZE,
        0, sizeof(size_t), malloc(sizeof(size_t) * STACK_DEFAULT_SIZE)}};

        push(&prm.stack, prm.left, prm.right);
        while (prm.stack.size) {
            update(&prm, pivot, bytes);
            while (prm.i < prm.j) {
                shrink(&prm, pivot, bytes, cmp);
                if (prm.i <= prm.j)
                    swap(&prm, bytes);
            }
            if (prm.i / bytes < prm.right)
                push(&prm.stack, prm.i / bytes, prm.right);
            if (prm.left < prm.j / bytes)
                push(&prm.stack, prm.left, (prm.j / bytes) + 1);
        }
        free(prm.stack.arr);
    }
}
