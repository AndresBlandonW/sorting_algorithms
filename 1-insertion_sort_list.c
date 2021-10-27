#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *list_end, *tmp, *move;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	list_end = *list;
	move = list_end;
	tmp = list_end->next;
	while (list_end->next != NULL)
	{
		if (tmp->n >= list_end->n)
		{
			list_end = tmp;
			tmp = tmp->next;
			move = list_end;
			continue;
		}
		while (tmp->n < move->n && move->prev != NULL && tmp->prev != NULL)
		{
			move = move->prev;
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->prev = move;
			tmp->next = move->next;
			move->next->prev = tmp;
			move->next = tmp;
			print_list(*list);
		}
		if (move->prev == NULL && tmp->n < move->n)
		{
			point_list(tmp, move);
			*list = tmp;
			print_list(*list);
		}
		move = list_end;
		if (list_end->next != NULL)
			tmp = list_end->next;
	}
}

/**
 * point_list - point the elements to sort
 * @tmp: list tmp
 * @move: pointer to move
 */
void point_list(listint_t *tmp, listint_t *move)
{
	move->prev = tmp;
	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	tmp->prev = NULL;
	tmp->next = move;
}
