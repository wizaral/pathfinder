#include "pathfinder.h"

static inline void add_route(t_info *info, t_vector *route) {
    size_t size = ((t_vector *)mx_at(&info->parents,
    mx_get_back(route)))->size;

    for (size_t i = 0; i < size; ++i) {
        mx_push_backward(route, mx_at(mx_at(&info->parents,
        *(size_t *)mx_get_back(route)), i));
        if (info->start != *(size_t *)mx_get_back(route))
            add_route(info, route);
        else
            mx_push_backward(&info->routes, route);  // переделать для копирования всего вектора
        mx_pop_backward(route);
    }
}

static inline void reverse(void *item) {
    mx_reverse_vector(item);
}

static inline int compare(const void *r1, const void *r2) {
    t_vector *v1 = (void *)r1;
    t_vector *v2 = (void *)r2;

    if (*(unsigned long long *)mx_get_back(v1)
    < *(unsigned long long *)mx_get_back(v2))
        return -1;
    if (*(unsigned long long *)mx_get_back(v1)
    == *(unsigned long long *)mx_get_back(v2)) {
        size_t stop = (v1->size < v2->size ? v1->size : v2->size);

        for (size_t i = 0; i < stop; ++i)
            if (*(unsigned long long *)mx_at(v1, i)
            != *(unsigned long long *)mx_at(v2, i))
                return *(unsigned long long *)mx_at(v1, i)
                - *(unsigned long long *)mx_at(v2, i);
    }
    return 1;
}

void mx_create_routes(t_info *info) {
    t_vector route;                     // определить переменные структуры

    for (unsigned long long i = info->start; i < info->size; ++i) {
        mx_push_backward(&route, &i);
        add_route(info, &route);
        mx_pop_backward(&route);
    }

    mx_foreach_vector(&info->routes, reverse);
    mx_sort_rec();
    mx_quicksort(&info->routes.arr, info->routes.size, info->routes.bytes,
    compare);
}
