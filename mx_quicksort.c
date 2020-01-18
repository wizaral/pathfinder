#include "libmx.h"

typedef struct s_parametrs {
    uint8_t *i;
    uint8_t *j;
    uint8_t *left;
    uint8_t *right;
    t_stack stack;
} t_parametrs;

typedef struct s_pivot {
    uint8_t *temp;
    int64_t pivot;
} t_pivot;

static inline void push(t_parametrs *prm, uint8_t *left, uint8_t *right) {
    mx_push(&prm->stack, &right);
    mx_push(&prm->stack, &left);
}

static inline void update(t_parametrs *prm, t_pivot *pivot, size_t bytes,
    int64_t (*w)(const void *)) {
    prm->i = prm->left = *(uint8_t **)mx_pop(&prm->stack);
    prm->j = prm->right = *(uint8_t **)mx_pop(&prm->stack);
    pivot->pivot = w(mx_memcpy(pivot->temp,
    prm->left + (prm->right - prm->left) / 2, bytes));
}

static inline void swap(t_parametrs *prm, size_t bytes) {
    mx_swap(prm->i, prm->j, bytes);
    prm->i += bytes;
    prm->j -= bytes;
}

static inline void add(t_parametrs *prm, size_t bytes) {
    uint8_t *left = prm->i;
    uint8_t *right = prm->j + bytes;

    if (left < prm->right)
        push(prm, left, prm->right);
    if (prm->left < right - bytes)
        push(prm, right, prm->left);
}

void mx_quicksort(void *arr, size_t size, size_t bytes,
    int64_t (*w)(const void *)) {
    if (arr && size > 1 && bytes > 0 && w) {
        uint8_t temp[bytes];
        t_pivot pivot = {temp, 0};
        t_parametrs prm = {arr, (uint8_t *)arr + (size - 1) * bytes, arr,
        (uint8_t *)arr + (size - 1) * bytes, {STACK_DEFAULT_SIZE, 0,
        sizeof(uint8_t *), malloc(sizeof(uint8_t *) * STACK_DEFAULT_SIZE)}};

        push(&prm, prm.left, prm.right);
        while (prm.stack.size) {
            update(&prm, &pivot, bytes, w);
            while (prm.i < prm.j) {
                for (; w(prm.i) < pivot.pivot; prm.i += bytes);
                for (; w(prm.j) > pivot.pivot; prm.j -= bytes);
                if (prm.i <= prm.j)
                    swap(&prm, bytes);
            }
            add(&prm, bytes);
        }
        free(prm.stack.arr);
    }
}