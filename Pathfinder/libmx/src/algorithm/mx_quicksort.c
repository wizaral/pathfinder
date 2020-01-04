#include "libmx.h"

static inline void add(t_parametrs *prm, size_t bytes) {
    size_t left = prm->i / bytes;
    size_t right = (prm->j / bytes) + 1;

    if (left < prm->right) {
        mx_push(&prm->stack, &prm->right);
        mx_push(&prm->stack, &left);
    }
    if (prm->left < right - 1) {
        mx_push(&prm->stack, &right);
        mx_push(&prm->stack, &prm->left);
    }
}

static inline void update(t_parametrs *prm, t_pivot *pivot, size_t bytes,
    long long (*w)(const void *)) {
    prm->i = (prm->left = *(size_t *)(mx_pop(&prm->stack))) * bytes;
    prm->j = (prm->right = *(size_t *)(mx_pop(&prm->stack))) * bytes;
    pivot->pivot = w(mx_memcpy(pivot->temp, (t_byte *)prm->arr
    + (prm->left + (prm->right - prm->left) / 2) * bytes, bytes));
}

static inline void shrink(t_parametrs *prm, t_pivot *pivot, size_t bytes,
    long long (*w)(const void *)) {
    for (; w((t_byte *)prm->arr + prm->i) < pivot->pivot; prm->i += bytes);
    for (; w((t_byte *)prm->arr + prm->j) > pivot->pivot; prm->j -= bytes);
}

static inline void swap(t_parametrs *prm, size_t bytes) {
    mx_swap((t_byte *)prm->arr + prm->i, (t_byte *)prm->arr + prm->j, bytes);
    prm->i += bytes;
    prm->j -= bytes;
}

void mx_quicksort(void *arr, size_t size, size_t bytes,
    long long (*w)(const void *)) {
    if (arr && size > 0 && bytes > 0 && w) {
        t_byte temp[bytes];
        t_pivot pivot = {temp, 0};
        t_parametrs prm = {arr, 0, size - 1, 0, size - 1, {STACK_DEFAULT_SIZE,
        0, sizeof(size_t), malloc(sizeof(size_t) * STACK_DEFAULT_SIZE)}};

        mx_push(&prm.stack, &prm.right);
        mx_push(&prm.stack, &prm.left);
        while (prm.stack.size) {
            update(&prm, &pivot, bytes, w);
            while (prm.i < prm.j) {
                shrink(&prm, &pivot, bytes, w);
                if (prm.i <= prm.j)
                    swap(&prm, bytes);
            }
            add(&prm, bytes);
        }
    }
}
