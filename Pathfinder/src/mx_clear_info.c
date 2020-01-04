#include "pathfinder.h"

static inline void set_inf(void *item) {
    *(unsigned long long *)item = INF;
}

static inline void set_zero(void *item) {
    *(char *)item = 0;
}

void clean_info(t_info *info) {
    unsigned long long inf = INF;
    char zero = false;

    for (size_t i = 0; i < info->parents.size; ++i)
        mx_clear(mx_at(&info->parents, i));

    mx_clear(&info->routes);
    mx_assign(&info->distances, info->distances.size, &inf);
    mx_assign(&info->visited, info->visited.size, &zero);
}
