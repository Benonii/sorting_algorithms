#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using an insertion algo
 * @list: The lsit to be sorted
 *
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *sorted = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		tmp = current;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			sorted = tmp->prev;
			if (tmp->next)
				tmp->next->prev = sorted;
			sorted->next = tmp->next;
			tmp->prev = sorted->prev;
			tmp->next = sorted;
			sorted->prev = tmp;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			print_list(*list);
		}
		current = current->next;
	}
}
