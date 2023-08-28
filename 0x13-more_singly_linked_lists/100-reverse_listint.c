#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @ptr_head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **ptr_head)
{
	listint_t *prev_node = NULL;
	listint_t *next_node = NULL;

	while (*ptr_head)
	{
		next_node = (*ptr_head)->next;
		(*ptr_head)->next = prev_node;
		prev_node = *ptr_head;
		*ptr_head = next_node;
	}

	*ptr_head = prev_node;

	return (*ptr_head);
}
