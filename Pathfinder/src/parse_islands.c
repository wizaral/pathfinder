#include "pathfinder.h"

size_t mx_check_island(t_info *info, t_file *file, char delim) {
    char *end = mx_strchr(file->file, delim);
    size_t result = SIZE_MAX;

    if (end == NULL && file->counter == 0)
        mx_throw_amount_error();
    if (end == file->file)
        mx_throw_line_error(file->line);
    for (char *i = file->file; i < end; ++i)
        if (!mx_isalpha(*i))
            mx_throw_line_error(file->line);
    for (size_t i = 0; i < file->counter && info->names[i]; ++i)
        if (mx_strncmp(info->names[i], file->file, end - file->file) == 0) {
            result = i;
            break;
        }
    if (result == SIZE_MAX && ((result = file->counter) || true))
        info->names[file->counter++] = mx_strndup(file->file, end - file->file);
    file->file = end + 1;
    return result;
}
