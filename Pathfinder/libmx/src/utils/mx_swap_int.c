#include "libmx.h"

void mx_swap_int(int *i1, int *i2) {
    if (i1 && i2) {
        int temp = *i1;
        *i1 = *i2;
        *i2 = temp;
    }
}
