#include "libmx.h"

long long mx_get_file_length(const char *filename) {
    int stream = open(filename, 0);
    long long length = 0;

    if (stream > -1) {
        long long delta = 1;
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
