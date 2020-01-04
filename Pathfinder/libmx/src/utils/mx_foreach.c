#include "libmx.h"

void mx_foreach(void *arr, size_t size, size_t bytes, void(*f)(void *)) {
    if (arr && f && size && bytes) {
        size_t end = size * bytes;

        for (size_t i = 0; i < end; i += bytes)
            f((t_byte *)arr + i);
    }
}
