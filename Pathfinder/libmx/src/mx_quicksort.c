#include "libmx.h"

static int sort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int swaps = 0;
    char *x = arr[left + (right - left) / 2];

    while (i <= j) {
        for (; mx_strlen(arr[i]) < mx_strlen(x); ++i);
        for (; mx_strlen(arr[j]) > mx_strlen(x); --j);

        if (i <= j) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[i]))
                mx_swap_str(arr + i, arr + j), ++swaps;
            ++i, --j;
        }
    }
    swaps = swaps > 0;
    swaps += i < right ? sort(arr, i, right) : 0;
    swaps += left < j ? sort(arr, left, j) : 0;
    return swaps;
}

int mx_quicksort(char **arr, int left, int right) {
    return arr ? sort(arr, left, right) : -1;
}
