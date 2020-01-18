#include "libmx.h"

static void printunum(uint64_t n, const int fd) {
    if (n > 9)
        printunum(n / 10, fd);
    mx_printchar(n % 10 + 48, fd);
}

void mx_printunum(uint64_t n, const int fd) {
    if (fd >= 0)
        printunum(n, fd);
}
