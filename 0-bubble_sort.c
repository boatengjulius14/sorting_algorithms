#include "sort.h"

/**
 * bubble_sort - implement the bubble sort algorithm
 *
 * @array: input
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, next_val, curr_val, check_sorted;

	if ((array == NULL) || (size == 1))
		return;

	check_sorted = bubble_best_case(array, size);
	if (check_sorted == 0)
		return;

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

				/* print array after swap */
				print_array(array, size);
			}
		}
	}
}

/**
 * bubble_best_case - check for best case
 *
 * @array: array of integers to be sorted
 * @size: size of array
 *
 * Return: 0 if best case; 1 otherwise
 */

int bubble_best_case(int *array, size_t size)
{
	int check;
	size_t j, curr_val, next_val;

	check = 0;

	for (j = 0; j < (size - 1); j++)
	{
		curr_val = array[j];
		next_val = array[j + 1];

		if (curr_val > next_val)
		{
			array[j] = next_val;
			array[j + 1] = curr_val;

			check = 1;
		}
	}

	if (check == 0)
		return (0);

	return (1);
}
