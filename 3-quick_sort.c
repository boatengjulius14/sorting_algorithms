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
	static size_t arr_len, temp = 1;
	int pivot, hi_val, curr_val, flag;
	size_t i, hi_val_index, pivot_index;

	if ((size <= 1) || (array == NULL))
		return;
	flag = 0;
	hi_val_index = -1;
	pivot_index = size - 1;
	pivot = array[size - 1];
	if (temp == 1) /* initialise array length on first run */
	{
		temp += 5;
		arr_len = size;
	}
	for (i = 0; i < (size - 1); i++)
	{
		curr_val = array[i];
		if ((flag == 0) && (curr_val > pivot))
		{ /* get the high value and its index */
			flag = 1;
			hi_val_index = i;
			hi_val = array[hi_val_index];
			continue;
		}
		if ((hi_val_index != (size_t) -1) && (pivot > curr_val))
		{ /* swap high value with value less than pivot and print arr*/
			array[i] = hi_val;
			array[hi_val_index] = curr_val;
			print_array(array, arr_len);
			hi_val_index = i;
		}
	}
	if (hi_val_index != (size_t) -1)
	{ /* swap pivot with last found high value and print array */
		size += 1;
		array[pivot_index] = hi_val;
		array[hi_val_index] = pivot;
		print_array(array, arr_len);
	} quick_sort(array, size - 1);
}
