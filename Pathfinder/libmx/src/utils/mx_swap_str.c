#include "libmx.h"

void mx_swap_str(char **s1, char **s2) {
    if (s1 && s2) {
        char *temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
}
