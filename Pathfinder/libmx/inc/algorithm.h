#pragma once

/*
* bsearch and lsearch return 0 if have not found item, so you need to
* check first item in container
*/

uint8_t *mx_binary_search(const void *key, t_vector *v,
int (*cmp)(const void *, const void *));
uint8_t *mx_linear_search(const void *key, t_vector *v,
int (*cmp)(const void *, const void *));

/*
* sort needs comparator for two arguments
* quicksort needs weight func for one element
*/

void mx_sort(void *arr, size_t size, size_t bytes,
int (*cmp)(const void *, const void *));
void mx_quicksort(void *arr, size_t size, size_t bytes,
int64_t (*wgt)(const void *));

/*
* checks array is sorted
*/

bool mx_checksort(const void *arr, size_t size, size_t bytes,
int (*cmp)(const void *, const void *));
