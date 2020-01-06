#include "pathfinder.h"

void mx_clear_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i)
        mx_clear_vector(mx_at(&info->parents, i));

    for (size_t i = 0; i < info->routes.size; ++i)
        mx_clear_vector(mx_at(&info->routes, i));

    mx_clear_vector(&info->routes);

    for (size_t i = 0; i < info->size; ++i)
        *((t_i64 *)mx_at(&info->distances, i)) = MX_INF;
    for (size_t i = 0; i < info->size; ++i)
        *((char *)mx_at(&info->visited, i)) = false;
}

void mx_delete_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i) {
        mx_delete_vector(mx_at(&info->graph, i));
        mx_delete_vector(mx_at(&info->parents, i));
        free(*(char **)mx_at(&info->names, i));
    }

    mx_delete_vector(&info->graph);
    mx_delete_vector(&info->parents);
    mx_delete_vector(&info->routes);
    mx_delete_vector(&info->distances);
    mx_delete_vector(&info->visited);
    mx_delete_vector(&info->names);
}
