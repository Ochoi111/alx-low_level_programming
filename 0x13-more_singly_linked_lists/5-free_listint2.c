#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 *
 * @head: A pointer to a pointer to the head of the list to free.
 */
void free_listint2(listint_t **head)
{
	listint_t *current_node, *next_node;

	if (!head)
		return;

	current_node = *head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}
