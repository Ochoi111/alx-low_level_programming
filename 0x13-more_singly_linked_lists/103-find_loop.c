#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slo = head;
	listint_t *fas = head;

	if (!head)
	return (NULL);

	while (slo && fas && fas->next)
	{
		fas = fas->next->next;
		slo = slo->next;
		if (fas == slo)
		{
			slo = head;
			while (slo != fas)
			{
				slo = slo->next;
				fas = fas->next;
			}
			return (fas);
		}
	}
	return (NULL);
}
