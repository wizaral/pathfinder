#include "pathfinder.h"

static inline void init(t_info *info, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        info->distances[i] = MX_INF;
        info->visited[i] = false;
        info->names[i] = NULL;
        info->parents[i].cap = VECTOR_DEFAULT_SIZE;
        info->parents[i].size = 0;
        info->parents[i].bytes = sizeof(size_t);
        info->parents[i].arr = malloc(sizeof(size_t) * VECTOR_DEFAULT_SIZE);
        info->graph[i].cap = VECTOR_DEFAULT_SIZE;
        info->graph[i].size = 0;
        info->graph[i].bytes = sizeof(t_pair);
        info->graph[i].arr = malloc(sizeof(t_pair) * VECTOR_DEFAULT_SIZE);
    }
}

void mx_init_info(t_info *info, size_t size) {
    info->size = size;
    info->distances = size ? malloc(sizeof(int) * size) : NULL;
    info->visited = size ? malloc(sizeof(char) * size) : NULL;
    info->names = size ? malloc(sizeof(char *) * size) : NULL;
    info->parents = size ? malloc(sizeof(t_vector) * size) : NULL;
    info->graph = size ? malloc(sizeof(t_vector) * size) : NULL;
    info->routes.bytes = sizeof(t_vector);
    info->routes.cap = VECTOR_DEFAULT_SIZE;
    info->routes.size = 0;
    info->routes.arr = size
    ? malloc(sizeof(t_vector) * VECTOR_DEFAULT_SIZE)
    : NULL;
    init(info, size);
}

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
