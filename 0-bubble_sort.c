#include "sort.h"

/**
 * bubble_sort - implement the bubble sort algorithm
 *
 * @array: input
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, check, next_val, curr_val;

	if ((array == NULL) || (size == 1))
		return;

	check = 0;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			curr_val = array[j];
			next_val = array[j + 1];

			if (curr_val > next_val)
			{
				array[j] = next_val;
				array[j + 1] = curr_val;

				check = 1;

				/* print array after swap */
				print_array(array, size);
			}
		}

		if (check == 0)
			break;
	}
}
