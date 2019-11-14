#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int result = 0;
    int swaps = 0;

    if (arr) {
        for (int i = 0; i < size; ++i, result += swaps, swaps = 0) {
            for (int j = 0; j < size - i - 1; ++j)
                if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                    mx_swap_str(arr + j, arr + j + 1);
                    ++swaps;
                }
            if (swaps == 0)
                break;
        }
    }
    return result;
}
