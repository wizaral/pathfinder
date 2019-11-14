#include "libmx.h"

static char *make_dec(int num, int length) {
    char *dec = mx_strnew(length);
    *dec = num < 0 ? '-' : '\0';

    for (int j = length - 1, temp; j >= (num <= 0); --j, num /= 10)
        dec[j] = ((temp = num % 10) < 0 ? -temp : temp) + 48;

    return dec;
}

char *mx_itoa(int number) {
    char *dec_str = NULL;

    if (number)
        dec_str = make_dec(number, mx_get_num_length(number, 10));
    else {
        dec_str = mx_strnew(1);
        *dec_str = '0';
    }
    return dec_str;
}
