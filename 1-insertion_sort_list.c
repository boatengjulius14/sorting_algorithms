#include "sort.h"

/**
 * insertion_sort_list - sort of the elements of a doubly linked list
 *
 * @list: head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next, *temp;

	temp = *list;
	(void) next;

	if (temp == NULL)
		return;

	for (; temp; temp = temp->next)
	{
		if (temp->prev != NULL)
		{
			prev = temp->prev;
			next = temp->next;

			for (; prev; prev = prev->prev)
			{
				if (temp->n < prev->n)
				{
					prev->next = temp->next;
					temp->next = prev;
					temp->prev = prev->prev;

					if (prev->prev != NULL)
						prev->prev = temp;
					else
						*list = temp;

					print_list(*list);
				}
			}
		}
	}
}
