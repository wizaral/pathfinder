#include "libmx.h"

void mx_foreach(int *arr, int size, void(*f)(int)) {
    for (int i = 0; arr && f && i < size; ++i)
        f(arr[i]);
}
