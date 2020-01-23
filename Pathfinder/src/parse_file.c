#include "pathfinder.h"

static inline int compare(const void *a, const void *b) {
    return (int)((t_pair *)a)->island - (int)((t_pair *)b)->island;
}

static inline void update_names(t_info *info, t_file *file) {
    if (file->names[0] && file->names[1]) {
        info->names[file->cntr - 2] = file->names[0];
        info->names[file->cntr - 1] = file->names[1];
        if (file->src.island == SIZE_MAX - 1)
            file->src.island = file->cntr - 2;
    }
    else if (file->names[0]) {
        info->names[file->cntr - 1] = file->names[0];
        if (file->src.island == SIZE_MAX - 1)
            file->src.island = file->cntr - 1;
    }
    else if (file->names[1])
        info->names[file->cntr - 1] = file->names[1];
    file->names[0] = file->names[1] = NULL;
}

static inline void add_new_path(t_info *info, t_file *file) {
    t_pair *result = (t_pair *)mx_lsearch(&file->src,
    &info->graph[file->dst.island], compare);

    if (!result) {
        update_names(info, file);
        if (file->dst.island != file->src.island) {
            file->full_len += file->src.distance;
            mx_push_backward(&info->graph[file->src.island], &file->dst);
            mx_push_backward(&info->graph[file->dst.island], &file->src);
        }
    }
    else {
        file->full_len -= result->distance;
        file->full_len += (result->distance = file->src.distance);
        result = (t_pair *)mx_lsearch(&file->dst,
        &info->graph[file->src.island], compare);
        result->distance = file->src.distance;
    }
    if (file->full_len > MX_INF)
        exit(0);
}

void mx_parse_file(t_info *info, t_file *file) {
    if ((file->file = mx_strchr(file->file, '\n')) && ++file->file) {
        for (; file->cntr <= info->size && *file->file; ++file->line) {
            file->dst.island = mx_check_island(info, file, '-');
            file->src.island = mx_check_island(info, file, ',');
            file->src.distance = file->dst.distance = mx_parse_distance(file);
            if (file->cntr <= info->size)
                add_new_path(info, file);
            else
                mx_throw_amount_error();
        }
        if (file->cntr != info->size) 
            mx_throw_amount_error();
    }
    else if (info->size)
        mx_throw_amount_error();
}
