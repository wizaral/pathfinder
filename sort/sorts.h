#ifndef sorts_h
#define sorts_h

void merge(int *array, int left, int right);
void mergesort(int *array, int left, int midle, int right);
void shellsort(int *array, int size);
void bubblesort(int *array, int size);
void selectionsort(int *array, int size);
void insertionsort(int *array, int size);
void quicksort(int *array, int first, int last);

void copy_values(int *array1, int *array2, int size)
void print_array(int *array, int size);
void swap(int *val1, int *val2)

#endif
