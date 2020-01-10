#include "pathfinder.h"

static inline void add_route(t_info *info, t_vector *route) {
    size_t size = info->parents[*(size_t *)mx_get_back(route)].size;

    for (size_t i = 0; i < size; ++i) {
        mx_push_backward(route, mx_at(&info->parents[*(size_t *)mx_get_back(route)], i));

        if (info->start != *(size_t *)mx_get_back(route))
            add_route(info, route);
        else {
            t_vector *v = mx_copy_vector(route);
            mx_push_backward(&info->routes, v);
            free(v);
        }
        mx_pop_backward(route);
    }
}

static inline void reverse(void *item) {
    mx_reverse_vector(item);
}

void mx_create_routes(t_info *info) {
    t_vector route = {VECTOR_DEFAULT_SIZE, 0, sizeof(size_t),
    malloc(sizeof(size_t) * VECTOR_DEFAULT_SIZE)};

    for (size_t i = info->start + 1; i < info->size; ++i) {
        mx_push_backward(&route, &i);
        add_route(info, &route);
        mx_pop_backward(&route);
    }
    mx_foreach_vector(&info->routes, reverse);
    mx_sort_routes(&info->routes);
    free(route.arr);
}
