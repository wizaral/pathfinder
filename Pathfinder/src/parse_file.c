#include "pathfinder.h"

static inline size_t check_island(t_info *info, char **start, size_t *counter,
size_t *line) {
    static bool phase = false;
    char *end = mx_strchr(*start, ((phase = !phase) ? '-' : ','));
    size_t result = SIZE_MAX;

    if (end == NULL && *counter == 0)
        mx_throw_amount_error();
    if (end == *start)
        mx_throw_line_error(*line);
    for (char *i = *start; i < end; ++i)
        if (!mx_isalpha(*i))
            mx_throw_line_error(*line);
    for (size_t i = 0; i < *counter && info->names[i]; ++i)
        if (mx_strncmp(info->names[i], *start, end - *start) == 0) {
            result = i;
            break;
        }
    if (result == SIZE_MAX && ((result = *counter) || true))
        info->names[(*counter)++] = mx_strndup(*start, end - *start);
    *start = end + 1;
    return result;
}

static inline int get_length(char **start, size_t *line) {
    char *end = mx_strchr(*start, '\n');
    int result = 0;

    if (end == *start || end == NULL)
        mx_throw_line_error(*line);
    for (char *i = *start; i < end; ++i)
        if (!mx_isdigit(*i))
            mx_throw_line_error(*line);
    result = mx_atoll(*start);
    *start = end + 1;
    return result;
}

static inline int compare(const void *a, const void *b) {
    return (int)((t_pair *)a)->island - (int)((t_pair *)b)->island;
}

static inline void add_new_path(t_info *info, t_pair *first, t_pair *second) {
    t_pair *result = (t_pair *)mx_linear_search(first,
    &info->graph[second->island], compare);

    if (!result) {
        mx_push_backward(&info->graph[first->island], second);
        mx_push_backward(&info->graph[second->island], first);
    }
    else {
        result->distance = first->distance;
        result = (t_pair *)mx_linear_search(second, &info->graph[first->island], compare);
        result->distance = first->distance;
    }
}

#include <stdio.h>

void mx_parse_file(t_info *info, char *file) {
    size_t size = mx_atoull(file);

    if ((file = mx_strchr(file, '\n')) && ++file) {
        t_pair first;
        t_pair second;
        size_t line = 2;

        for (size_t counter = 0; counter <= size && *file; ++line) {
            second.island = check_island(info, &file, &counter, &line);
            first.island = check_island(info, &file, &counter, &line);
            first.distance = second.distance = get_length(&file, &line);
            add_new_path(info, &first, &second);
        }
    }
}
