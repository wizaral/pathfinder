#include "pathfinder.h"

static inline int compare(const void *a, const void *b) {
    return (int)((t_pair *)a)->island - (int)((t_pair *)b)->island;
}

static inline void add_new_path(t_info *info, t_file *file) {
    t_pair *result = (t_pair *)mx_linear_search(&file->first,
    &info->graph[file->second.island], compare);

    if (!result) {
        mx_push_backward(&info->graph[file->first.island], &file->second);
        mx_push_backward(&info->graph[file->second.island], &file->first);
    }
    else {
        result->distance = file->first.distance;
        result = (t_pair *)mx_linear_search(&file->second, &info->graph[file->first.island], compare);
        result->distance = file->first.distance;
    }
}

#include <stdio.h>

void mx_parse_file(t_info *info, t_file *file) {
    if ((file->file = mx_strchr(file->file, '\n')) && ++file->file) {
        for (; file->counter <= info->size && *file->file; ++file->line) {
            file->second.island = mx_check_island(info, file, '-');
            file->first.island = mx_check_island(info, file, ',');
            file->first.distance = file->second.distance = mx_parse_distance(file);
            add_new_path(info, file);
        }
    }
}
