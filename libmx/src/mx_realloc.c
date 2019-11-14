#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr = NULL;
    size_t old_size = malloc_size(ptr);

    if (ptr == NULL)
        return malloc(size);
    else if (old_size && size == 0)
        free(ptr);
    else if (size && (new_ptr = malloc(mx_max_ull(size, old_size)))) {
        mx_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }
    return new_ptr;
}
