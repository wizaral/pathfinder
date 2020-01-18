#include "libmx.h"

typedef struct s_parametrs {
    uint8_t *i;
    uint8_t *j;
    uint8_t *left;
    uint8_t *right;
    t_stack stack;
} t_parametrs;

static inline void update(t_parametrs *prm, uint8_t *pivot, size_t bytes) {
    prm->i = prm->left = *(uint8_t **)mx_pop(&prm->stack);
    prm->j = prm->right = *(uint8_t **)mx_pop(&prm->stack);
    mx_memcpy(pivot, prm->left + (prm->right - prm->left) / 2, bytes);
}

static inline void swap(t_parametrs *prm, size_t bytes) {
    mx_swap(prm->i, prm->j, bytes);
    prm->i += bytes;
    prm->j -= bytes;
}

static inline void add(t_parametrs *prm, size_t bytes) {
    uint8_t *left = prm->i;
    uint8_t *right = prm->j + bytes;

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
        uint8_t pivot[bytes];
        t_parametrs prm = {arr, (uint8_t *)arr + (size - 1) * bytes, arr,
        (uint8_t *)arr + (size - 1) * bytes, {STACK_DEFAULT_SIZE, 0,
        sizeof(uint8_t *), malloc(sizeof(uint8_t *) * STACK_DEFAULT_SIZE)}};

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
