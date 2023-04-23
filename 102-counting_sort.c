#include "sort.h"

/**
* max_element - returns the largest number in an array
* @array: pointer to array
* @size: size of array
* Return: largest number in the array
*/
int max_element(int *array, size_t size)
{
	int k = array[0], i;

	for (i = 1; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];
	return (k);
}

/**
* counting_sort - sorts an array of integers in ascending
* order using the counting sort algorithm
* @array: pointer to array
* @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int *count_array, *final_array;
	int i, k;

	if (size <= 1)
		return;
	k = max_element(array, size);
	count_array = malloc(sizeof(int) * (k + 1));
	if (count_array == NULL)
		return;

	for (i = 0; i <= k; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= k; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, k + 1);

	final_array = malloc(sizeof(int) * size);

	if (final_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		final_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = final_array[i];

	free(count_array);
	free(final_array);
}
