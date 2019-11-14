#include "libmx.h"

static void printnum(int n) {
    if (n > 9)
        printnum(n / 10);
    mx_printchar(n % 10 + 48);
}

void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    printnum(n);
}
