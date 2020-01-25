#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr = NULL;
    size_t old_size = MX_MALLOC_SIZE(ptr);

    if (ptr == NULL)
        return malloc(size);
    else if (size && (new_ptr = malloc(MX_MAX(size, old_size, size_t))))
        mx_memcpy(new_ptr, ptr, old_size);
    if (old_size)
        free(ptr);
    return new_ptr;
}
