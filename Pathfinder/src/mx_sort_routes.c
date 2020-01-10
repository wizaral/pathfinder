#include "pathfinder.h"

#include <stdio.h>

static inline int compare(t_vector *r1, t_vector *r2) {
    if (*(size_t *)mx_get_back(r1) < *(size_t *)mx_get_back(r2))
        return -1;
    if (*(size_t *)mx_get_back(r1) == *(size_t *)mx_get_back(r2)) {
        size_t stop = MX_MIN(r1->size, r2->size, size_t);

        for (size_t i = 1; i < stop; ++i)
            if (*(size_t *)mx_at(r1, i) != *(size_t *)mx_at(r2, i))
                return *(size_t *)mx_at(r1, i) - *(size_t *)mx_at(r2, i);
    }
    return 1;
}

// static inline void sort(t_vector *routes, int left, int right) {
//     int i = left;
//     int j = right;
//     t_vector *pivot = &routes[left + (right - left) / 2];

//     // printf("1: I: %i, J: %i, P: %i\n", i, j, left + (right - left) / 2);

//     while (i < j) {
//         for (; compare(&routes[i], pivot) < 0; ++i);
//         for (; compare(&routes[j], pivot) > 0; --j);
//         // printf("22: I: %i, J: %i\n", i, j);

//         if (i <= j)
//             mx_swap(&routes[i++], &routes[j--], sizeof(t_vector));
//     }

//     // printf("333: I: %i, J: %i\n", i, j);

//     if (left < j) {
//         // printf("left < j\n");
//         sort(routes, left, j);
//     }
//     if (i < right) {
//         // printf("i < right\n");
//         sort(routes, i, right);
//     }
// }

static inline void sort(t_vector *routes, int size) {
    for (int i = size - 1; i > 0; --i)
        for (int j = size - i; j > 0; --j)
            if (compare(routes + j - 1, routes + j) > 0)
                mx_swap(routes + j - 1, routes + j, sizeof(t_vector));
}

void mx_sort_routes(t_vector *routes) {
    if (routes->arr && routes->size > 1 && routes->bytes > 0)
        sort((t_vector *)routes->arr, routes->size);
        // sort((t_vector *)routes->arr, 0, routes->size - 1);
}
