#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"
#include "dk_tool.h"
#include "searches.h"
#include "cor_types.h"

int line_search(int val, int size, int *array)
{
	for(int i = 0; i < size; i++)
		if(array[i] == val)
			return i;

	return -1;
}

int binary_search(int val, int size, int *array)
{
	int middle, lower = 0, upper = size - 1;
	while(lower <= upper)
	{
		middle = lower + (upper - lower) / 2;

		if(array[middle] == val)
			return middle;

		else if(array[middle] < val)
			lower = middle + 1;

		else
			upper = middle - 1;
	}
	return -1;
}
