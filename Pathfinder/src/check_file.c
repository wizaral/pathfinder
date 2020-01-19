#include "pathfinder.h"

static inline size_t check_line(char *line) {
    size_t len = mx_strlen(line);
    size_t result = 0;

    if (len == 0)
        mx_throw_line_error(1);
    for (size_t i = 0; i < len; ++i)
        if (!mx_isdigit(line[i]))
            mx_throw_line_error(1);
    if ((result = mx_atoull(line)) > 10000000)
        exit(0);
    free(line);
    return result;
}

size_t mx_check_file(const char *filename) {
    char *line = NULL;

    if (filename) {
        int stream = open(filename, 0);
        int64_t result = mx_read_line(&line, '\n', stream);

        if (result > -2) {
            close(stream);
            if (result > -1)
                return check_line(line);
            else if (result == -1)
                mx_throw_file_empty_error(filename);
        }
        else
            mx_throw_file_exist_error(filename);
    }
    return 0;
}
