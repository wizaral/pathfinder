#include "pathfinder.h"

// #include <stdio.h>

static inline size_t get_min(t_info *info) {
    size_t visit = MX_INF;

    for (size_t j = 0; j < info->size; ++j)
        if (info->visited[j] == false && (visit == MX_INF || info->distances[j] < info->distances[visit]))
            visit = j;
    return visit;
}

static inline void check_distance(t_info *info, size_t visit, size_t j) {
    size_t island = ((t_pair *)mx_at(&info->graph[visit], j))->island;
    int distance = ((t_pair *)mx_at(&info->graph[visit], j))->distance;

    // printf("island: %zu\n", island);
    // printf("dist: %i\n", dist);

    if (info->distances[visit] + distance <= info->distances[island]) {
        if (info->distances[visit] + distance < info->distances[island]) {
            mx_clear_vector(mx_at(&info->parents, island));
            info->distances[island] = info->distances[visit] + distance;
        }
        mx_push_backward(&info->parents[island], &visit);
    }
}

static inline void dijkstra(t_info *info) {
    size_t size;
    size_t visit;

    for (size_t i = 0; i < info->size; ++i) {
        visit = get_min(info);
        // printf("%zu %i\n", visit, info->distances[visit]);

        if (info->distances[visit] == MX_INF)
            break;

        info->visited[visit] = true;
        size = info->graph[visit].size;

        for (size_t j = 0; j < size; ++j)
            check_distance(info, visit, j);
    }
}

void mx_algorithm(t_info *info) {
    for (size_t i = 0; i < info->size - 1; ++i) {
        info->distances[i] = 0;
        info->start = i;
        dijkstra(info);

        mx_create_routes(info);
        mx_print_routes(info);
        mx_clear_info(info);
    }
}
