#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @ptr_head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **ptr_head)
{
	listint_t *current_node;

	if (ptr_head == NULL)
		return;

	while (*ptr_head)
	{
		current_node = (*ptr_head)->next;
		free(*ptr_head);
		*ptr_head = current_node;
	}

	*ptr_head = NULL;
}
