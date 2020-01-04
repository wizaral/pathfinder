#include "pathfinder.h"

void mx_clean_info(t_info *info) {
    size_t inf = INF;
    char zero = false;

    for (size_t i = 0; i < info->parents.size; ++i)
        mx_clear_vector(*(t_vector **)mx_at(&info->parents, i));

    mx_clear_vector(&info->routes);
    mx_assign_vector(&info->distances, info->distances.size, &inf);
    mx_assign_vector(&info->visited, info->visited.size, &zero);
}
