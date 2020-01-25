#include "libmx.h"

void mx_printchar(char c, const int fd) {
    if (fd >= 0)
        write(fd, &c, 1);
}
