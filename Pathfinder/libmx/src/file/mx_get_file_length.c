#include "libmx.h"

long long mx_get_file_length(const char *filename) {
    int stream = open(filename, 0);
    long long length = 0;

    for (char buffer; read(stream, &buffer, 1) > 0; ++length);

    close(stream);
    return stream >= 0 ? length : -1;
}
