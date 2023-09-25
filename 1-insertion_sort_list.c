#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @s1: first node to swap.
 * @s2: second node to swap.
 *
 * Return: void
 */
void swap(listint_t *s1, listint_t *s2)
{
	if (s1->prev)
		s1->prev->next = s2;
	if (s2->next)
		s2->next->prev = s1;
	s1->next = s2->next;
	s2->prev = s1->prev;
	s1->prev = s2;
	s2->next = s1;
}

/**
 * insertion_sort_list - insertion sorts a doubly linked list of int.
 * @list: adrss of pointer to head node.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
