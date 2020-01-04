#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "types.h"
#include "structs.h"

typedef struct s_parametrs {
    void *arr;
    size_t i;
    size_t j;
    size_t left;
    size_t right;
    t_stack stack;
} t_parametrs;

typedef struct s_pivot {
    t_byte *temp;
    long long pivot;
} t_pivot;

/*
* bsearch and lsearch return 0 if have not found item, so you need to
* check first item in container
*/

size_t mx_binary_search(const void *key, t_vector *v, int (*cmp)(const void *, const void *));
size_t mx_linear_search(const void *key, t_vector *v, int (*cmp)(const void *, const void *));

/*
* sort needs comparator for two arguments
* quicksort needs weight func for one element
*/

void mx_sort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));
void mx_quicksort(void *arr, size_t size, size_t bytes, long long (*w)(const void *));

void mx_sort_rec(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));
void mx_quicksort_rec(void *arr, size_t size, size_t bytes, long long (*w)(const void *));

/*
* checks array is sorted
*/

bool mx_checksort(const void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));

#endif
