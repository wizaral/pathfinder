#include "pathfinder.h"

static inline int64_t check_argument(t_file *file, char *line, char *end) {
    for (; *line == '0'; ++line);
    if (*line) {
        size_t len = end - line;

        if (len > 10)
            mx_throw_line_error(file->line);
        else if (len == 10 && mx_strncmp(line, "2147483647", 10) > 0)
            mx_throw_line_error(file->line);
        else
            return mx_atoll(line);
    }
    return 0;
}

int mx_parse_distance(t_file *file) {
    char *end = mx_strchr(file->file, '\n');
    int result = 0;

    if (end == NULL || end == file->file)
        mx_throw_line_error(file->line);
    for (char *i = file->file; i < end; ++i)
        if (!mx_isdigit(*i))
            mx_throw_line_error(file->line);
    result = check_argument(file, file->file, end);
    if (result + file->full_len > MX_INF)
        exit(0);
    file->file = end + 1;
    file->full_len += result;
    return result;
}

size_t check_array(t_info *info, t_file *file, char *end) {
    size_t result = SIZE_MAX;

    for (size_t i = 0; i < info->size && i < file->cntr && info->names[i]; ++i)
        if (mx_strncmp(info->names[i], file->file, end - file->file) == 0)
            return i;
    if (file->names[0]
        && !mx_strncmp(file->names[0], file->file, end - file->file))
        result -= 1;
    return result;
}

size_t mx_check_island(t_info *info, t_file *file, char delim) {
    char *end = mx_strchr(file->file, delim);
    size_t result = SIZE_MAX;

    if (end == NULL || end == file->file)
        mx_throw_line_error(file->line);
    for (char *i = file->file; i < end; ++i)
        if (!mx_isalpha(*i))
            mx_throw_line_error(file->line);
    result = check_array(info, file, end);
    if (result == SIZE_MAX) {
        result = file->cntr++;
        file->names[delim == ','] = mx_strndup(file->file, end - file->file);
    }
    file->file = end + 1;
    return result;
}
