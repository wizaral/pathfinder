#include "libmx.h"

char *mx_strnew(const int size) {
    char *ptr = NULL;

    if (size >= 0 && (ptr = (char *)malloc(size + 1)) != NULL)
        for (int i = 0; i <= size; ++i)
            ptr[i] = '\0';

    return ptr;
}
