#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @ptr_head: pointer to the first element in the linked list
 *
 * Return: the data inside the element that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **ptr_head)
{
	listint_t *temp_node;
	int data;

	if (!ptr_head || !*ptr_head)
		return (0);

	data = (*ptr_head)->n;
	temp_node = (*ptr_head)->next;
	free(*ptr_head);
	*ptr_head = temp_node;

	return (data);
}
