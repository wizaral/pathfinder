#include "pathfinder.h"

void mx_clear_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i)
        mx_clear_vector(&info->parents[i]);

    for (size_t i = 0; i < info->routes.size; ++i)
        free(((t_vector *)mx_at(&info->routes, i))->arr);
    mx_clear_vector(&info->routes);

    for (size_t i = 0; i < info->size; ++i) {
        info->distances[i] = MX_INF;
        info->visited[i] = false;
    }
}

void mx_delete_info(t_info *info) {
    for (size_t i = 0; i < info->size; ++i) {
        free(info->graph[i].arr);
        free(info->parents[i].arr);
        free(info->names[i]);
    }

    free(info->graph);
    free(info->parents);
    free(info->names);
    free(info->visited);
    free(info->distances);
    free(info->routes.arr);
}
