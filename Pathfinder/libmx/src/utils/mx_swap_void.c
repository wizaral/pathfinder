#include "libmx.h"

void mx_swap_void(void **v1, void **v2) {
    if (v1 && v2) {
        void *temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }
}
