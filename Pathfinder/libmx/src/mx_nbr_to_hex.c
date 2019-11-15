#include "libmx.h"

static char *make_hex(unsigned long nbr, unsigned length) {
    char *hex = mx_strnew(length);

    for (int j = length - 1; j >= 0; --j, nbr >>= 4)
        hex[j] = nbr % 16 < 10 ? nbr % 16 + 48 : nbr % 16 + 87;

    return hex;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    return nbr ? make_hex(nbr, mx_get_num_length(nbr, 16)) : mx_strdup("0");
}
