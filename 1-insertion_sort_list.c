#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to pointer to first node of the list
*/

void insertion_sort_list(listint_t **list)
{
	int flag = 0;
	listint_t *temp_main = *list, *temp, *prevo, *nexto;

	if (temp_main == NULL && temp_main->next == NULL)
		return;
	while (temp_main != NULL)
	{
		temp = temp_main;
		while (temp_main != *list && temp->prev->n > temp->n)
		{
			prevo = temp->prev;
			nexto = temp->next;
			temp->prev = prevo->prev;
			prevo->next = temp->next;
			prevo->prev = temp;
			temp->next = prevo;
			if (temp->prev != NULL)
				temp->prev->next = temp;

			if (nexto != NULL)
				nexto->prev = prevo;

			if (temp->prev == NULL)
			{
				*list = temp;
				print_list(*list);
				break;
			}
			print_list(*list);
			if (flag == 0)
			{
				if (temp->next != NULL)
					temp_main = temp->next->next;
				flag = 1;
			}
		}
		if (flag == 0)
			temp_main = temp_main->next;
		flag = 0;
	}
}
