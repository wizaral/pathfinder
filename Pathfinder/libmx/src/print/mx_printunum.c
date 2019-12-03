#include "libmx.h"

void mx_printunum(t_ull n, const int fd) {
    if (fd >= 0) {
        if (n > 9)
            mx_printunum(n / 10, fd);
        mx_printchar(n % 10 + 48, fd);
    }
}
