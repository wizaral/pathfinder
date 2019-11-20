#include "libmx.h"

// void mx_quicksort(char **arr, int left, int right) {
//     int i = left;
//     int j = right;
//     int x = arr ? mx_strlen(arr[left + (right - left) / 2]) : 0;

//     if (arr) {
//         while (i < j) {
//             for (; mx_strlen(arr[i]) < x; ++i);
//             for (; mx_strlen(arr[j]) > x; --j);

//             if (i <= j) {
//                 if (mx_strlen(arr[j]) < mx_strlen(arr[i]))
//                     mx_swap_str(arr + i, arr + j);
//                 ++i, --j;
//             }
//         }
//         if (i < right)
//             sort(arr, i, right);
//         if (left < j)
//             sort(arr, left, j);
//     }
// }
