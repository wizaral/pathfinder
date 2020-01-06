#include "pathfinder.h"

void mx_clear_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i)
        mx_clear_vector(mx_at(&info->parents, i));

    for (size_t i = 0; i < info->routes.size; ++i) {
        free(((t_vector *)mx_at(&info->routes, i))->arr);
        // mx_clear_vector(mx_at(&info->routes, i));
        // free((t_vector *)mx_at(&info->routes, i));
    }

    mx_clear_vector(&info->routes);
    // free(info->routes.arr);

    for (size_t i = 0; i < info->size; ++i)
        *((t_i64 *)mx_at(&info->distances, i)) = MX_INF;
    for (size_t i = 0; i < info->size; ++i)
        *((char *)mx_at(&info->visited, i)) = false;
}

void mx_delete_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i) {
        free(((t_vector *)mx_at(&info->graph, i))->arr);
        free(((t_vector *)mx_at(&info->parents, i))->arr);
        free(*(char **)mx_at(&info->names, i));
    }

    free(info->graph.arr);
    free(info->parents.arr);
    free(info->routes.arr);
    free(info->distances.arr);
    free(info->visited.arr);
    free(info->names.arr);
}
