#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: pointer to the head of the list
 *
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *temp;

	if (h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		len++;
		temp = current;
		current = current->next;
		free(temp);
		if (temp <= current)
			break;
	}
	*h = NULL;

	return (len);
}
