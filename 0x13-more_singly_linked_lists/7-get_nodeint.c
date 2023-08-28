#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @ptr_head: first node in the linked list
 * @target_index: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *ptr_head, unsigned int target_index)
{
	unsigned int current_index = 0;
	listint_t *current_node = ptr_head;

	while (current_node && current_index < target_index)
	{
		current_node = current_node->next;
		current_index++;
	}

	return (current_node ? current_node : NULL);
}
