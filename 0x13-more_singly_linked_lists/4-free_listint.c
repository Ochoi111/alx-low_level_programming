#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 *
 * @head: A pointer to the head of the list to free.
 */
void free_listint(listint_t *head)
{
	listint_t *current_node, *next_node;

	if (!head)
		return;

	current_node = head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
