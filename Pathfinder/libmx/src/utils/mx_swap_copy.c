#include "libmx.h"

void mx_swap_copy(void *v1, void *v2, size_t size) {
    if (v1 && v2) {
        void *temp = mx_memcpy(malloc(size), v1, size);
        mx_memcpy(v1, v2, size);
        mx_memcpy(v2, temp, size);
        free(temp);
    }
}
