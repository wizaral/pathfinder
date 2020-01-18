#include "libmx.h"

uint8_t *mx_bsearch(const void *key, t_vector *v,
int (*cmp)(const void *, const void *)) {
    if (v && v->size && v->bytes && v->arr && key && cmp) {
        uint8_t *left = v->arr;
        uint8_t *right = v->arr + (v->size - 1) * v->bytes;
        uint8_t *middle = NULL;
        int result;

        while (left <= right) {
            middle = left + (right - left) / 2;
            result = cmp(key, middle);
            if (result > 0)
                left = middle + v->bytes;
            else if (result < 0)
                right = middle - v->bytes;
            else
                return middle;
        }
    }
    return NULL;
}
