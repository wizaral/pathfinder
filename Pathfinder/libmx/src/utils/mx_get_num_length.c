#include "libmx.h"

int mx_get_num_length(t_i64 nbr, unsigned base) {
    int result = nbr < 0;

    for (; nbr; nbr /= base, ++result);
    return result;
}
