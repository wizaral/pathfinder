#include "pathfinder.h"

static inline unsigned long long get_min(t_info *info) {
    unsigned long long visit = INF;

    for (unsigned long long j = 0; j < info->size; ++j)
        if (*(char *)mx_at(&info->visited, j) == false
        && (visit == INF || *(unsigned long long *)mx_at(&info->distances, j)
        < *(unsigned long long *)mx_at(&info->distances, visit)))
            visit = j;
    return visit;
}

static inline void check_distance(t_info *info, unsigned long long visit,
    unsigned long long j) {
    unsigned long long island =((t_pair *)mx_at(mx_at(&info->graph, visit),
    j))->island;
    unsigned long long distance = ((t_pair *)mx_at(mx_at(&info->graph, visit),
    j))->distance;

    if (*(unsigned long long *)mx_at(&info->distances, visit) + distance
    <= *(unsigned long long *)mx_at(&info->distances, island)) {
        if (*(unsigned long long *)mx_at(&info->distances, visit) + distance
        < *(unsigned long long *)mx_at(&info->distances, island)) {
            mx_clear(mx_at(&info->parents, island));
            *(unsigned long long *)mx_at(&info->distances, island) =
            *(unsigned long long *)mx_at(&info->distances, visit) + distance;
        }
        mx_push_backward(mx_at(&info->parents, island), &visit);
    }
}

static inline void dijkstra(t_info *info) {
    unsigned long long size;
    unsigned long long visit;

    for (unsigned long long i = 0; i < info->size; ++i) {
        visit = get_min(info);
        if (*(unsigned long long *)mx_at(&info->distances, visit) == INF)
            break;

        *(char *)mx_at(&info->visited, visit) = true;
        size = ((t_vector *)mx_at(&info->graph, visit))->size;
        for (unsigned long long j = 0; j < size; ++j)
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
        clean_info(info);
    }
}
