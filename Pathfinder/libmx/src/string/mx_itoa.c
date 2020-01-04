#include "libmx.h"

static char *make_dec(int num, int length) {
    char *dec = mx_strnew(length);

    *dec = num < 0 ? '-' : '\0';
    for (int j = length - 1; j >= (num <= 0); --j, num /= 10)
        dec[j] = MX_ABS(num % 10) + 48;
    return dec;
}

char *mx_itoa(int nbr) {
    return nbr ? make_dec(nbr, mx_get_num_length(nbr, 10)) : mx_strdup("0");
}
