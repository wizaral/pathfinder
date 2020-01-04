#include "pathfinder.h"

#include <stdio.h>

static inline size_t get_min(t_info *info) {
    size_t visit = INF;

    for (size_t j = 0; j < info->size; ++j)
        if (*(char *)mx_at(&info->visited, j) == false && (visit == INF || *(size_t *)mx_at(&info->distances, j) < *(size_t *)mx_at(&info->distances, visit)))
            visit = j;
    return visit;
}

static inline void check_distance(t_info *info, size_t visit, size_t j) {
    size_t island = ((t_pair *)mx_at(*(t_vector **)mx_at(&info->graph, visit), j))->island;
    size_t distance = ((t_pair *)mx_at(*(t_vector **)mx_at(&info->graph, visit), j))->distance;

    // printf("island: %zu\n", island);
    // printf("distance: %zu\n", distance);

    if (*(size_t *)mx_at(&info->distances, visit) + distance
    <= *(size_t *)mx_at(&info->distances, island)) {
        if (*(size_t *)mx_at(&info->distances, visit) + distance
        < *(size_t *)mx_at(&info->distances, island)) {
            mx_clear_vector(*(t_vector **)mx_at(&info->parents, island));
            *(size_t *)mx_at(&info->distances, island) =
            *(size_t *)mx_at(&info->distances, visit) + distance;
        }
        mx_push_backward(*(t_vector **)mx_at(&info->parents, island), &visit);
    }
}

static inline void dijkstra(t_info *info) {
    size_t size;
    size_t visit;

    for (size_t i = 0; i < info->size; ++i) {
        visit = get_min(info);

        // printf("%zu %zu\n", visit, *(size_t *)mx_at(&info->distances, visit));

        if (*(size_t *)mx_at(&info->distances, visit) == INF)
            break;

        *(char *)mx_at(&info->visited, visit) = true;
        size = (*(t_vector **)mx_at(&info->graph, visit))->size;

        // printf("%zu %zu\n", (*(t_vector **)mx_at(&info->graph, visit))->size, size);

        for (size_t j = 0; j < size; ++j)
            check_distance(info, visit, j);
    }
}

void mx_algorithm(t_info *info) {
    for (size_t i = 0; i < info->size - 1; ++i) {
        *(size_t *)mx_at(&info->distances, i) = 0;
        info->start = i;
        dijkstra(info);

        mx_create_routes(info);
        mx_print_routes(info);
        mx_clean_info(info);
    }
}
