#include "pathfinder.h"

static inline int compare(const void *a, const void *b) {
    return (int)((t_pair *)a)->island - (int)((t_pair *)b)->island;
}

static inline void add_new_path(t_info *info, t_file *file) {
    t_pair *result = (t_pair *)mx_linear_search(&file->src,
    &info->graph[file->dst.island], compare);

    if (!result) {
        mx_push_backward(&info->graph[file->src.island], &file->dst);
        mx_push_backward(&info->graph[file->dst.island], &file->src);
    }
    else {
        result->distance = file->src.distance;
        result = (t_pair *)mx_linear_search(&file->dst, &info->graph[file->src.island], compare);
        result->distance = file->src.distance;
    }
}

void mx_parse_file(t_info *info, t_file *file) {
    if ((file->file = mx_strchr(file->file, '\n'))) {
        ++file->file;

        for (; file->counter <= info->size && *file->file; ++file->line) {
            file->dst.island = mx_check_island(info, file, '-');
            file->src.island = mx_check_island(info, file, ',');
            file->src.distance = file->dst.distance = mx_parse_distance(file);
            add_new_path(info, file);
        }
    }
}
