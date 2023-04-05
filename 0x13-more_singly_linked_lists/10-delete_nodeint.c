#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list
 * @head: double pointer to head node of linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (current == NULL || current->next == NULL)
			return (-1);
		current = current->next;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}
