#include "libmx.h"

void mx_swap_char(char *c1, char *c2) {
    if (c1 && c2) {
        char temp = *c1;
        *c1 = *c2;
        *c2 = temp;
    }
}
