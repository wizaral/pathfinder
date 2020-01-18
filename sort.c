#include <intrin.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static inline void swap(int *restrict i1, int *restrict i2) {
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

void sortc(int *arr, int size) {
    int step = size;

    for (int k = 0; size > 1; k = 0) {
        (step /= 1.247f) < 1 ? (step = 1) : step;
        for (int i = 0; i + step < size; ++i)
            if (arr[i] > arr[i + step])
                swap(arr + (k = i), arr + i + step);
        (step == 1) ? (size = k + 1) : step;
    }
}

void sortc2(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *)) {
    size_t step = size * bytes;
    unsigned char *stop = (unsigned char *)arr + size * bytes;

    for (unsigned char *k = NULL; stop > (unsigned char *)arr + bytes; k = NULL) {
        (step /= 1.247f * bytes) < 1 ? (step = bytes) : (step *= bytes);

        for (unsigned char *i = arr; i + step < stop; i += bytes)
            if (cmp(i, i + step) > 0)
                swap((void *)(k = i), (void *)(i + step));

        (step == bytes) ? (stop = k + bytes) : stop;
    }
}

bool checksort(int *arr, int size) {
    bool result = true;
    for (int i = 1; i < size; ++i)
        if (arr[i - 1] > arr[i])
            result = false;
    return result;
}

int main() {
    srand(time(NULL));
    const int size = 10000000;
    int *arr1 = malloc(sizeof(int) * size);
    int *arr2 = malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i)
        arr2[i] = arr1[i] = rand();

    // printf("%i\n", time(NULL));
    // printf("%llu\n", __rdtsc());
    unsigned int64_t tStart1 = __rdtsc();
    sortc(arr1, size);
    // qsort(arr1, size, sizeof(int), compare);
    // printf("S1\n");
    unsigned int64_t tEnd1 = __rdtsc();
    // printf("%llu\n", __rdtsc());
    // printf("%i\n", time(NULL));

    printf("%s\n", checksort(arr1, size) ? "sorted" : "unsorted");

    // printf("%i\n", time(NULL));
    // printf("%llu\n", __rdtsc());
    unsigned int64_t tStart2 = __rdtsc();
    sortc2(arr2, size, sizeof(int), compare);
    // printf("S2\n");
    // qsort(arr2, size, sizeof(int), compare);
    unsigned int64_t tEnd2 = __rdtsc();

    // printf("%llu\n", __rdtsc());
    // printf("%i\n", time(NULL));

    printf("%s\n", checksort(arr2, size) ? "sorted" : "unsorted");

    printf("%llu\n", tEnd1 - tStart1);
    printf("%llu\n", tEnd2 - tStart2);
    printf("%llu\n", ((tEnd2 - tStart2) < (tEnd1 - tStart1)) ? ((tEnd1 - tStart1) - (tEnd2 - tStart2)) : ((tEnd2 - tStart2) - (tEnd1 - tStart1)));
}
