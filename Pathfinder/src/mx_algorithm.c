#include "pathfinder.h"

// #include <stdio.h>

static inline size_t get_min(t_info *info) {
    size_t visit = MX_INT_MAX;

    for (size_t j = 0; j < info->size; ++j)
        if (*(char *)mx_at(&info->visited, j) == false
        && (visit == MX_INT_MAX
        || *(t_i64 *)mx_at(&info->distances, j) < *(t_i64 *)mx_at(&info->distances, visit)))
            visit = j;
    return visit;
}

static inline void check_distance(t_info *info, size_t visit, size_t j) {
    size_t island = ((t_pair *)mx_at(mx_at(&info->graph, visit), j))->island;
    t_i64 distance = ((t_pair *)mx_at(mx_at(&info->graph, visit), j))->dist;

    // printf("island: %zu\n", island);
    // printf("dist: %llu\n", dist);

    if (distance != MX_INF && *(t_i64 *)mx_at(&info->distances, visit) + distance <= *(t_i64 *)mx_at(&info->distances, island)) {
        if (*(t_i64 *)mx_at(&info->distances, visit) + distance < *(t_i64 *)mx_at(&info->distances, island)) {
            mx_clear_vector(mx_at(&info->parents, island));

            *(t_i64 *)mx_at(&info->distances, island) = *(t_i64 *)mx_at(&info->distances, visit) + distance;
        }
        mx_push_backward(mx_at(&info->parents, island), &visit);
    }
}

static inline void dijkstra(t_info *info) {
    size_t size;
    size_t visit;

    for (size_t i = 0; i < info->size; ++i) {
        visit = get_min(info);

        // printf("%zu %zu\n", visit, *(size_t *)mx_at(&info->distances, visit));

        if (*(t_i64 *)mx_at(&info->distances, visit) == MX_INF)
            break;

        *(char *)mx_at(&info->visited, visit) = true;
        size = ((t_vector *)mx_at(&info->graph, visit))->size;

        // printf("%zu %zu\n", (*(t_vector **)mx_at(&info->graph, visit))->size, size);

        for (size_t j = 0; j < size; ++j)
            check_distance(info, visit, j);
    }
}

void mx_algorithm(t_info *info) {
    for (size_t i = 0; i < info->size - 1; ++i) {
        *(t_i64 *)mx_at(&info->distances, i) = 0;
        info->start = i;
        dijkstra(info);

        mx_create_routes(info);

        mx_print_routes(info);
        mx_clear_info(info);
    }
}
