#include "pathfinder.h"

int mx_parse_distance(t_file *file) {
    char *end = mx_strchr(file->file, '\n');
    int result = 0;

    if (end == file->file || end == NULL)
        mx_throw_line_error(file->line);
    for (char *i = file->file; i < end; ++i)
        if (!mx_isdigit(*i))
            mx_throw_line_error(file->line);
    result = mx_atoll(file->file);
    file->file = end + 1;
    return result;
}
