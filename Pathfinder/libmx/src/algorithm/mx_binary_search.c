#include "libmx.h"

size_t mx_binary_search(const void *key, t_vector *v,
    int (*cmp)(const void *, const void *)) {
    size_t left = 0;
    size_t right = v ? v->size - 1 : 0;
    size_t middle = 0;
    size_t result;

    if (v && v->size && v->arr && key && cmp) {
        while (left <= right) {
            middle = left + (right - left) / 2;
            result = cmp(key, (t_byte *)v->arr + (middle * v->bytes));
            if (result > 0)
                left = middle + 1;
            else if (result < 0)
                right = middle - 1;
            else
                return middle;
        }
    }
    return 0;
}
