#include "libmx.h"

int mx_read_line(char **lineptr, char delim, const int fd) {
    size_t len = 0;
    size_t lim = 16;
    int write_bytes = 1;

    if (read(fd, NULL, 0) < 0) {
        *lineptr = mx_realloc(*lineptr, 0);
        return -2;
    }

    *lineptr = (char *)mx_realloc(*lineptr, lim);

    for (; *lineptr && write_bytes > 0; len += write_bytes != 0) {
        len >= lim ? *lineptr = (char *)mx_realloc(*lineptr, lim *= 2) : NULL;
        write_bytes = *lineptr ? read(fd, *lineptr + len, 1) : -1;

        if (*lineptr && (*lineptr)[len] == delim)
            break;
    }

    if (*lineptr && (*lineptr = (char *)mx_realloc(*lineptr, len + 1)))
        (*lineptr)[len] = '\0';
    return *lineptr ? (write_bytes > 0 ? mx_strlen(*lineptr) : -1) : -2;
}
