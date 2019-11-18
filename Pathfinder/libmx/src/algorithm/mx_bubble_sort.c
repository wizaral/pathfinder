#include "libmx.h"

void mx_bubble_sort(char **arr, int size) {
    for (int i = 0, swaps = 0; arr && i < size; ++i, swaps = 0) {
        for (int j = 0; j < size - i - 1; ++j)
            if (mx_strcmp(arr[j], arr[j + 1]) > 0)
                mx_swap_str(arr + j, arr + j + 1), ++swaps;
        if (swaps == 0)
            break;
    }
}
