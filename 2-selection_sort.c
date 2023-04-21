#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection sort algorithm
* @array: pointer to array;
* @size: size of array;
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int low_pos, tmp, flag = 0;

	if (size == 0 || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		low_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[low_pos] > array[j])
			{
				low_pos = j;
				flag = 1;
			}
		}
		tmp = array[i];
		array[i] = array[low_pos];
		array[low_pos] = tmp;

		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}
