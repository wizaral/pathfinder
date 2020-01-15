#include "pathfinder.h"

static inline size_t get_min(t_info *info) {
    size_t visit = MX_INF;

    for (size_t j = 0; j < info->size; ++j)
        if (info->visited[j] == false
            && (info->distances[j] < info->distances[visit]
            || visit == MX_INF))
            visit = j;
    return visit;
}

static inline void check_distance(t_info *info, size_t visit, size_t j) {
    size_t island = ((t_pair *)mx_at(&info->graph[visit], j))->island;
    int distance = ((t_pair *)mx_at(&info->graph[visit], j))->distance;

    if (info->distances[visit] + distance <= info->distances[island]) {
        if (info->distances[visit] + distance < info->distances[island]) {
            mx_clear_vector(&info->parents[island]);
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
        if (info->distances[visit] == MX_INF)
            break;
        info->visited[visit] = true;
        size = info->graph[visit].size;
        for (size_t j = 0; j < size; ++j)
            check_distance(info, visit, j);
    }
}

#include <stdio.h>

void mx_algorithm(t_info *info) {
    printf("START: %zu\n", info->size);
    for (size_t i = 0; i < info->size - 1; ++i) {
        printf("MID\n");
        info->distances[i] = 0;
        info->start = i;
        dijkstra(info);
        mx_create_routes(info);
        mx_print_routes(info);
        mx_clear_info(info);
    }
    printf("END\n");
}
