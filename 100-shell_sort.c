#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
* using shell sort
* @array: array to sort
* @size: size of array to sort
*/
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap = 1;

	if (size == 0 || size == 1)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			for (; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
