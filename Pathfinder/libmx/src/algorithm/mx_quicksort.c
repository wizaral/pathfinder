#include "libmx.h"

#include <time.h>
#include <stdio.h>
#include <string.h>

void mx_quicksort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    if (arr && size > 0 && bytes > 0 && cmp) {
        t_ull i = 0;
        t_ull j = (size - 1) * bytes;
        void *x = (t_uc *)arr + (size / 2) * bytes;

        while (i <= j) {
            for (; cmp((t_uc *)arr + i, x) < 0; i += bytes);
            for (; cmp((t_uc *)arr + j, x) > 0; j -= bytes);

            if (i <= j) {
                if (cmp((t_uc *)arr + i, (t_uc *)arr + j) > 0)
                    mx_swap_copy((t_uc *)arr + i, (t_uc *)arr + j, bytes);
                i += bytes, j -= bytes;
            }
        }

        if (i / bytes < (size - 1)) {
            printf("I: %llu %zu %llu\n", i / bytes, size, size - i / bytes);
            mx_quicksort((t_uc *)arr + i, size - i / bytes, bytes, cmp);
        }
        if (0 < j / bytes) {
            printf("J: %llu %zu %llu\n", j / bytes, size, size - 1 - j / bytes);
            mx_quicksort((t_uc *)arr, size - 1 - j / bytes, bytes, cmp);
        }
    }
}

int cmp(const void *a, const void *b) {
    return mx_strlen(*(char **)a) - mx_strlen(*(char **)b);
}

void print(char **arr, int size) {
    for (int i = 0; i < size; ++i)
        printf(":%s:\n", arr[i]);
    printf("\n");
}

bool check_sort(char **arr, int size) {
    for (int i = 0, j = 1; j < size; ++i, ++j)
        if (mx_strlen(arr[i]) > mx_strlen(arr[j]))
            return false;
    return true;
}

int main() {
    int size = 40;

    char **arr = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = mx_strnew(100);

        for (int j = 0; j < rand() % 100; ++j)
            for (int k = 0; k < j; ++k)
                arr[i][k] = 65 + rand() % 26;
    }

    time_t t1 = time(0);
    printf("START\n");
    mx_quicksort(arr, size, sizeof(arr[0]), cmp);
    printf("FINISH\n");
    time_t t2 = time(0);

    printf("Sorted array:\n");
    print(arr, size);

    printf("%li\n", t2 - t1);
    printf("%s\n", check_sort(arr, size) ? "sorted" : "not sorted");
}
