#include "libmx.h"

// void mx_mergesort(void *arr, size_t size, size_t bytes,
//     int (*cmp)(const void *, const void *))
// {

// }

// static int min(int a, int b) {
//     return a < b ? a : b;
// }

// void mergesort(int *arr, int size) {
//     for (int i = 1; i < size; i *= 2)
//         for (int j = 0; j < size - i; j += 2 * i)
//             merge(arr, j, j + i, min(j + 2 * i, size));
// }

#include <stdio.h>

static inline void merge(void *l, void *m, void *r, void *buf, size_t bytes, int (*cmp)(const void *, const void *)) {
    void *cl = l, *cr = m;
    t_ull cur = 0;

    // while (cl < m && cr < r)
    //     buf[cur++] = *cl < *cr ? *cl++ : *cr++;
    while (cl < m && cr < r) {
        if (cmp(cl, cr) < 0)
            mx_memcpy((t_uc *)buf + cur, cl, bytes), cl += bytes;
        else
            mx_memcpy((t_uc *)buf + cur, cr, bytes), cr += bytes;
        cur += bytes;
    }

    // while (cl < m)
    //     buf[cur++] = *cl++;
    while (cl < m)
        mx_memcpy((t_uc *)buf + cur, cl, bytes), cl += bytes, cur += bytes;
    // while (cr < r)
    //     buf[cur++] = *cr++;
    while (cr < r)
        mx_memcpy((t_uc *)buf + cur, cr, bytes), cr += bytes, cur += bytes;

    // for (int *i = l, cur = 0; i < r; i++)
    //     *i = buf[cur++];
    mx_memcpy(l, buf, r - l);
}

static void _mergesort(void *left, void *right, void *buf, size_t bytes, int (*cmp)(const void *, const void *)) {
    void *mid = left + (right - left) / 2;
    printf("%i\n", *(int *)mid);

    if (right - left > bytes) {
        _mergesort(left, mid, buf, bytes, cmp);
        _mergesort(mid, right, buf, bytes, cmp);
        merge(left, mid, right, buf, bytes, cmp);
    }
}

void mx_mergesort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
// void mx_mergesort(int *arr, int size) {
    void *buf = malloc(bytes * size);
    _mergesort(arr, (t_uc *)arr + size * bytes, buf, bytes, cmp);
    free(buf);
}

#include <time.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    srand(time(NULL));
    int size = 20;

    int* arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;

    for (int i = 0; i < size; ++i)
        printf("%i, ", arr[i]);
    printf("\n\n");
        
    mx_mergesort(arr, size, sizeof(int), compare);

    for (int i = 0; i < size; ++i)
        printf("%i, ", arr[i]);

    printf("\n");
    free(arr);
}
