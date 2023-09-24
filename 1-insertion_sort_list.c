#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using an insertion algorithm
 * @list: The lsit to be sorted
 *
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *sorted = NULL, *next = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while(current)
	{
		next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			tmp = sorted;
			while (tmp->next && tmp->next->n < current->n)
				tmp = tmp->next;

			current->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = current;
			tmp->next = current;
			current->prev = tmp;
		}

		print_list(sorted);
		current = next;
	}

	*list = sorted;
}
