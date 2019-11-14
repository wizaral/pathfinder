#include "libmx.h"

int mx_get_num_length(long long nbr, unsigned base) {
    int result = nbr < 0;

    for (; nbr; nbr /= base, ++result);
    return result;
}
