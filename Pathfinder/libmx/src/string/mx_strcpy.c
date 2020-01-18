#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    for (int i = 0; src[i++]; dst[i] = src[i]);
    *dst = *src;
    return dst;
}
