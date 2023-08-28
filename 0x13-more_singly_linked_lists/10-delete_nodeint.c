#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @ptr_head: pointer to the first element in the list
 * @target_index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **ptr_head, unsigned int target_index)
{
	listint_t *temp = *ptr_head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*ptr_head == NULL)
		return (-1);

	if (target_index == 0)
	{
		*ptr_head = (*ptr_head)->next;
		free(temp);
		return (1);
	}

	while (i < target_index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
