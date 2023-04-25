#include "sort.h"

/**
* heapify - create a complete max heap out of array elements
* @array: array
* @size: size of array
* @top_node: the top/root node
* @sub_elem: position of sub elements
*/
void heapify(int *array, size_t size, size_t top_node, size_t sub_elem)
{
	size_t L, R, max;
	int temp;

	L = 2 * top_node + 1;
	R = 2 * top_node + 2;

	max = top_node;
	if (sub_elem > L && array[L] > array[max])
		max = L;
	if (sub_elem > R && array[R] > array[max])
		max = R;

	if (max != top_node)
	{
		temp = array[top_node];
		array[top_node] = array[max];
		array[max] = temp;

		print_array(array, size);
		heapify(array, size, max, sub_elem);
	}
}

/**
* heap_sort - sorts an array of integers in ascending order using
* the Heap sort algorithm.
* @array: pointer to array
* @size: size of array
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (size <= 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
