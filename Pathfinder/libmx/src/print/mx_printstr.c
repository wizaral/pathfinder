#include "libmx.h"

void mx_printstr(const char *s, const int fd) {
    if (fd >= 0)
        write(fd, s, mx_strlen(s));
}
