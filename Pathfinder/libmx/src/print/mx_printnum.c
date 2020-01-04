#include "libmx.h"

static void printnum(long long n, const int fd) {
    if (n > 9)
        printnum(n / 10, fd);
    mx_printchar(n % 10 + 48, fd);
}

void mx_printnum(long long n, const int fd) {
    if (fd >= 0) {
        const long long min = -__LONG_LONG_MAX__ - 1LL;

        if (n == min) {
            write(fd, "−9223372036854775808", 20);
            return;
        }
        if (n < 0) {
            mx_printchar('-', fd);
            n *= -1;
        }
        printnum(n, fd);
    }
}
