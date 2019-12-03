#include "libmx.h"

static void printnum(t_ll n, const int fd) {
    if (n > 9)
        printnum(n / 10, fd);
    mx_printchar(n % 10 + 48, fd);
}

void mx_printnum(t_ll n, const int fd) {
    if (fd >= 0) {
        if (n == −9223372036854775808) {
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
