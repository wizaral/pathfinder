#include "pathfinder.h"

static inline void print_route(t_info *info, t_vector *route) {
    for (size_t i = 0; i < route->size - 1; ++i) {
        mx_printstr(mx_at(&info->names, *(size_t *)mx_at(route, i)));
        mx_printstr(" -> ");
    }
    mx_printstr(mx_at(&info->names, *(size_t *)mx_at(route, route->size - 1)));
}

static inline void print_distance(t_info *info, t_vector *route) {
    unsigned long long dist = 0;

    for (size_t i = 1; i < route->size - 1; ++i) {
        mx_printunum(*(unsigned long long *)mx_at(&info->distances,
        *(size_t *)mx_at(route, i)) - dist);
        mx_printstr(" + ");
        dist = *(unsigned long long *)mx_at(&info->distances,
        *(size_t *)mx_at(route, i));
    }
    mx_printunum(*(unsigned long long *)mx_at(&info->distances,
    *(size_t *)mx_at(route, route->size - 1)) - dist);
    mx_printstr(" = ");
    mx_printunum(*(unsigned long long *)mx_at(&info->distances,
    *(size_t *)mx_at(route, route->size - 1)));
}

void mx_print_routes(t_info *info) {
    for (size_t i = 0; i < info->routes.size; ++i) {
        mx_printstr("========================================\nPath: ");
        mx_printstr(mx_at(&info->names,
        *(size_t *)mx_at(mx_at(&info->routes, i), 0)));
        mx_printstr(" -> ");
        mx_printstr(mx_at(&info->names,
        *(size_t *)mx_at(mx_at(&info->routes, i),
        ((t_vector *)mx_at(&info->routes, i))->size - 1)));
        mx_printstr("\nRoute: ");
        print_route(info, mx_at(&info->routes, i));
        mx_printstr("Distance: ");
        if (((t_vector *)mx_at(&info->routes, i))->size > 2)
            print_distance(info, mx_at(&info->routes, i));
        else
            mx_printunum(*(unsigned long long *)mx_at(&info->distances,
            *(size_t *)mx_at(mx_at(&info->routes, i),
            ((t_vector *)mx_at(&info->routes, i))->size - 1)));
        mx_printstr("\n========================================\n");
    }
}
