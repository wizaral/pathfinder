#include "pathfinder.h"

static inline ull get_min(Info &info) {
    ull visited = INF;

    for (ull j = 0; j < info.size; ++j)
        if (info.visited[j] == false && (visited == INF || info.distances[j] < info.distances[visited]))
            visited = j;
    return visited;
}

static inline void check_distance(Info &info, ull visited, ull j) {
    auto [to, len] = info.graph[visited][j];

    if (info.distances[visited] + len <= info.distances[to]) {
        if (info.distances[visited] + len < info.distances[to]) {
            info.distances[to] = info.distances[visited] + len;
            info.parents[to].clear();
        }
        if (len || info.visited[to] == false)
            info.parents[to].push_back(visited);
    }
}

static inline void dijkstra(Info &info) {
    for (ull i = 0, visited; i < info.size; ++i) {
        if (visited = get_min(info); info.distances[visited] != INF) {
            info.visited[visited] = true;
            for (ull j = 0, size = info.graph[visited].size(); j < size; ++j)
                check_distance(info, visited, j);
        }
    }
}

void algorithm(Info &info) {
    for (size_t i = 0; i < info.size - 1; ++i) {
        info.distances[i] = 0;
        info.start = i;
        dijkstra(info);

        create_routes(info);
        print_routes(info);
        info.clean_info();
    }
}
