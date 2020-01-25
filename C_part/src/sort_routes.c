#include "pathfinder.h"

static inline bool compare(t_vector *r1, t_vector *r2) {
    if (*(size_t *)mx_get_back(r1) < *(size_t *)mx_get_back(r2))
        return true;
    if (*(size_t *)mx_get_back(r1) == *(size_t *)mx_get_back(r2)) {
        size_t stop = MX_MIN(r1->size, r2->size, size_t);

        for (size_t i = 1; i < stop; ++i)
            if (*(size_t *)mx_at(r1, i) != *(size_t *)mx_at(r2, i))
                return *(size_t *)mx_at(r1, i) < *(size_t *)mx_at(r2, i);
    }
    return false;
}

static inline void sort(t_vector *arr, size_t size) {
    size_t step = size;

    for (size_t k = 0; size > 1; k = 0) {
        (step /= 1.247f) < 1 ? (step = 1) : 0;
        for (size_t i = 0; i + step < size; ++i)
            if (compare(arr + i, arr + i + step) == false)
                mx_swap(arr + (k = i), arr + i + step, sizeof(t_vector));
        (step == 1) ? (size = k + 1) : 0;
    }
}

void mx_sort_routes(t_vector *routes) {
    if (routes->arr && routes->size > 1 && routes->bytes > 0)
        sort((t_vector *)routes->arr, routes->size);
}
