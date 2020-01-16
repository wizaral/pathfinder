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
    return result > 0 ? result : result + 1;
}

size_t mx_check_file(const char *filename) {
    char *line = NULL;
    int stream = 0;

    if (filename) {
        if ((stream = open(filename, 0)) >= 0) {
            if (mx_read_line(&line, '\n', stream) > -1)
                return check_line(line);
            else
                mx_throw_file_empty_error(filename);
        }
        else
            mx_throw_file_exist_error(filename);
        close(stream);
    }
    return 0;
}
