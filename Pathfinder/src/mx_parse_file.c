#include "pathfinder.h"

#include <stdio.h>

// static inline void check_lines(t_info *info, char *file, size_t size) {
//     size_t counter = 0;

// }

void mx_parse_file(t_info *info, const char *filename) {
    char *file = filename && info ? mx_file_to_str(filename) : NULL;
    // size_t size = mx_atoull(file);   // info->size;

    if (file) {
        // printf(":%llu:\n", mx_atoull(file));
        // check_lines(info, file, size);
    }
    else
        exit(0);
}
