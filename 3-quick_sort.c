#include "sort.h"

/**
 * quick_sort - sort the elements of an array\
 *              using the quick sort algorithm
 *
 * @array: array whose elements are to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int i, curr_val, pivot, temp, first_val;
	size_t array_size;

	if ((size <= 1) || (array == NULL))
		return;

	first_val = array[0];
	pivot = array[size - 1];
	curr_val = size - 1;

	for (i = (size - 2); i >= 0; i--)
	{
		if (array[i] > pivot)
		{
			--curr_val;
			temp = array[i];
			array[i] = array[curr_val];
			array[curr_val] = temp;
		}
	}

	array[i + 1] = pivot;
	array[size - 1] = first_val;
	print_array(array, 10);

	quick_sort(array, size - 1);
}
