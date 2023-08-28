#include "lists.h"

/**
 * free_listint - frees a linked list
 * @h: listint_t list to be freed
 */
void free_listint(listint_t *h)
{
	listint_t *current;
	listint_t *next_node;

	current = h;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
