#include "libmx.h"

static inline void update(t_parametrs *prm, t_byte *pivot, size_t bytes) {
    prm->i = prm->left = *(t_byte **)mx_pop(&prm->stack);
    prm->j = prm->right = *(t_byte **)mx_pop(&prm->stack);
    mx_memcpy(pivot, prm->left + (prm->right - prm->left) / 2, bytes);
}

static inline void swap(t_parametrs *prm, size_t bytes) {
    mx_swap(prm->i, prm->j, bytes);
    prm->i += bytes;
    prm->j -= bytes;
}

static inline void add(t_parametrs *prm, size_t bytes) {
    t_byte *left = prm->i;
    t_byte *right = prm->j + bytes;

    if (left < prm->right) {
        mx_push(&prm->stack, &prm->right);
        mx_push(&prm->stack, &left);
    }
    if (prm->left < right - bytes) {
        mx_push(&prm->stack, &right);
        mx_push(&prm->stack, &prm->left);
    }
}

void mx_sort(void *arr, size_t size, size_t bytes,
    int (*cmp)(const void *, const void *)) {
    if (arr && size > 1 && bytes > 0 && cmp) {
        t_byte pivot[bytes];
        t_parametrs prm = {arr, (t_byte *)arr + (size - 1) * bytes, arr,
        (t_byte *)arr + (size - 1) * bytes, {STACK_DEFAULT_SIZE, 0,
        sizeof(t_byte *), malloc(sizeof(t_byte *) * STACK_DEFAULT_SIZE)}};

        mx_push(&prm.stack, &prm.right);
        mx_push(&prm.stack, &prm.left);
        while (prm.stack.size) {
            update(&prm, pivot, bytes);
            while (prm.i < prm.j) {
                for (; cmp(prm.i, pivot) < 0; prm.i += bytes);
                for (; cmp(prm.j, pivot) > 0; prm.j -= bytes);
                if (prm.i <= prm.j)
                    swap(&prm, bytes);
            }
            add(&prm, bytes);
        }
        free(prm.stack.arr);
    }
}
