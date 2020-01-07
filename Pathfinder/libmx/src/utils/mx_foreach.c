#include "libmx.h"

void mx_foreach(void *arr, size_t size, size_t bytes, void(*f)(void *)) {
    if (arr && f && size && bytes) {
        t_byte *end = (t_byte *)arr + size * bytes;

        for (t_byte *i = arr; i < end; i += bytes)
            f(i);
    }
}
