#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"
#include "dk_tool.h"
#include "searches.h"
#include "cor_types.h"

void merge(int *array, int left, int right)
{
	if(left < right)
	{
		int midle = left + (right - left) / 2;
		merge(array, left, midle);
		merge(array, midle + 1, right);
		mergesort(array, left, midle, right);
	}
}

void mergesort(int *array, int left, int midle, int right)
{
	int n1 = midle - left + 1;
	int n2 =  right - midle;
	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
		L[i] = array[left + i];

	for(int j = 0; j < n2; j++)
		R[j] = array[midle + 1 + j];

	int i = 0, j = 0, k = left;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

void shellsort(int *array, int size)
{
	int H = 1;

	while(H <= size / 3)
		H = H * 3 + 1;

	while(H > 0)
	{
		for(int j = H; j < size; j++)
		{
			int tmp = array[j];
			i = j;

			for(int i = 0; i > H - 1 && array[i - H] >= tmp; i -= H)
				array[i] = array[i - H];

			array[i] = tmp;
		}
		H = (H - 1) / 3;
	}
}

void bubblesort(int *array, int size)
{
	for(int i = size - 1; i > 0; i--)
		for(int j = 0; j < i; j++)
			if(array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}

void selectionsort(int *array, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for(int j = i + 1; j < size; j++)
			if(array[j] < array[min_index])
				min_index = j;

		swap(&array[i], &array[min_index]);
	}
}

void insertionsort(int *array, int size)
{
	for(int i = 1; i < size; i++)
	{
		int tmp = array[i];
		for(int j = i; j > 0 && array[j - 1] >= tmp; j--)
			array[j] = array[j - 1];

		array[j] = tmp;
	}
}

void quicksort(int *array, int first, int last)
{
	int i = first, j = last, x = array[(first + last) / 2];
	do
	{
		while(array[i] < x)
			i++;
		while(array[j] > x)
			j--;

		if(i <= j)
		{
			if(array[i] > array[j])
				swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	while(i <= j);

	if(i < last)
		quicksort(array, i, last);
	if(first < j)
		quicksort(array, first, j);
}

void copy_values(int *array1, int *array2, int size)
{
	for(int i = 0; i < size; i++)
		array1[i] = array2[i];
}

void swap(int *val1, int *val2)
{
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void print_array(int *array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%i ", array[i]);
	printf("\n");
}
