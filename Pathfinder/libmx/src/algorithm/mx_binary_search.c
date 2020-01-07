#include "libmx.h"

t_byte *mx_binary_search(const void *key, t_vector *v,
    int (*cmp)(const void *, const void *)) {
    t_byte *left = v ? v->arr : NULL;
    t_byte *right = v ? v->arr + (v->size - 1) * v->bytes : NULL;
    t_byte *middle = NULL;
    int result;

    if (v && v->size && v->arr && key && cmp) {
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
