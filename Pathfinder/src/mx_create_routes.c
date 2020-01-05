#include "pathfinder.h"

// #include <stdio.h>

static inline void add_route(t_info *info, t_vector *route) {
    // printf("back: %zu\n", *(size_t *)mx_get_back(route));
    size_t size = (*(t_vector **)mx_at(&info->parents, *(size_t *)mx_get_back(route)))->size;

    for (size_t i = 0; i < size; ++i) {
        mx_push_backward(route, mx_at(*(t_vector **)mx_at(&info->parents, *(size_t *)mx_get_back(route)), i));

        if (info->start != *(size_t *)mx_get_back(route)) {
            // printf("back: %zu\n", *(size_t *)mx_get_back(route));
            add_route(info, route);
        }
        else {
            t_vector *temp = mx_copy_vector(route);
            mx_push_backward(&info->routes, &temp);
        }
        mx_pop_backward(route);
    }
}

static inline void reverse(void *item) {
    mx_reverse_vector(*(t_vector **)item);
}

static inline int compare(const void *r1, const void *r2) {
    t_vector *v1 = *(t_vector **)r1;
    t_vector *v2 = *(t_vector **)r2;

    if (*(size_t *)mx_get_back(v1) < *(size_t *)mx_get_back(v2))
        return -1;
    if (*(size_t *)mx_get_back(v1) == *(size_t *)mx_get_back(v2)) {
        size_t stop = (v1->size < v2->size ? v1->size : v2->size);

        for (size_t i = 0; i < stop; ++i)
            if (*(size_t *)mx_at(v1, i) != *(size_t *)mx_at(v2, i))
                return *(size_t *)mx_at(v1, i) - *(size_t *)mx_at(v2, i);
    }
    return 1;
}

void mx_create_routes(t_info *info) {
    t_vector route = {VECTOR_DEFAULT_SIZE, 0, sizeof(size_t), malloc(sizeof(size_t) * VECTOR_DEFAULT_SIZE)};

    for (size_t i = info->start; i < info->size; ++i) {
        mx_push_backward(&route, &i);
        add_route(info, &route);
        mx_pop_backward(&route);
    }

    mx_foreach_vector(&info->routes, reverse);
    // printf("%zu %zu %zu\n", info->routes.bytes, info->routes.cap, info->routes.size);
    mx_sort_rec(info->routes.arr, info->routes.size, info->routes.bytes,
    compare);
}
