#include "libmx.h"

int mx_linear_search(char **arr, int size, const char *s) {
    for (int i = 0; i < size; ++i)
        if (mx_strcmp(s, arr[i]) == 0)
            return i;
    return -1;
}
