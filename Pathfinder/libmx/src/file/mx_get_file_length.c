#include "libmx.h"

t_i64 mx_get_file_length(const char *filename) {
    int stream = open(filename, 0);
    t_i64 length = 0;

    if (stream > -1) {
        t_i64 delta = 1;
        char buffer[1024];

        while (delta) {
            delta = length;
            length += read(stream, buffer, 1024);
            delta -= length;
        }
        close(stream);
        return length;
    }
    return -1;
}
