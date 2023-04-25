#include "sort.h"

/**
* bitonic_count - merges bitonic sequences
* @array: array
* @size: the size of array
* @lowindex: index of first element in the sequence
* @count: the size of sequence to merge
* @direction: order of sequence to merge
*/
void bitonic_merge(int *array, size_t size, size_t lowindex, size_t count,
		int direction)
{
	size_t i, k;
	int temp;

	k = count / 2;
	if (count > 1)
	{
		for (i = lowindex; i < lowindex + k; i++)
		{
			if ((direction == 1 && array[i] > array[i + k]) ||
			    (direction == 0 && array[i] < array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		bitonic_merge(array, size, lowindex, k, direction);
		bitonic_merge(array, size, lowindex + k, k, direction);
	}
}


/**
* bitonic_count - produces bitonic sequences from array elements
* @array: array
* @size: the size of array
* @lowindex: index of first element in the sequence
* @count: the size of sequence
* @direction: order of sequence
*/
void bitonic_count(int *array, size_t size, size_t lowindex, size_t count,
		int direction)
{
	size_t k;
	char *dir_str;

	k = count / 2;

	if (direction == 1)
		dir_str = "UP";
	else
		dir_str = "DOWN";

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count, size, dir_str);
		print_array(array + lowindex, count);

		bitonic_count(array, size, lowindex, k, 1);
		bitonic_count(array, size, lowindex + k, k, 0);
		bitonic_merge(array, size, lowindex, count, direction);

		printf("Result [%lu/%lu] (%s):\n", count, size, dir_str);
		print_array(array + lowindex, count);
	}
}


/**
* bitonic_sort - sorts an array of integers in ascending order
* using the Bitonic sort algorithm
* @array: array
* @size: size of array
*/
void bitonic_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	bitonic_count(array, size, 0, size, 1);
}
