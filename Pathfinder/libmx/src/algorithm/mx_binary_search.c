#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s) {
    int left = 0;
    int right = size - 1;
    int middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (mx_strcmp(s, arr[middle]) == 0)
            return middle;
        else if (mx_strcmp(arr[middle], s) > 0)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
