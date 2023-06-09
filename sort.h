#ifndef SORT_H
#define SORT_H

/* import standard libraries */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* function prototypes */
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void counting_sort(int *array, size_t size);
int max_element(int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t top_node, size_t sub_elem);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t lowindex,
		size_t count, int direction);
void bitonic_count(int *array, size_t size, size_t lowindex,
		size_t count, int direction);
#endif
