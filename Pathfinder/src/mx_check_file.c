#include "pathfinder.h"

#include <stdio.h>

static inline int check_line(const char *line) {
    printf(":%s:\n", line);
    free((void *)line);
    return 0;
}

int mx_check_file(const char *filename) {
    char *line = NULL;

    if (filename) {
        int stream = open(filename, 0);

        if (stream >= 0) {
            if ((mx_read_line(&line, '\n', stream)) > 0)
                return check_line(line);
            else
                mx_throw_file_empty_error(filename);
        }
        else
            mx_throw_file_exist_error(filename);
    }
    return 0;
}
