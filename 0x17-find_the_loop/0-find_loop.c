#include "lists.h"

/**
 * find_listint_loop - Detects if a linked list has a loop.
 * @head: A pointer to head of list.
 * Return: A pointer to the beginning of the loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise;
	listint_t *hare;

	if (!head)
		return (NULL);
	tortoise = hare = head;
	while (hare->next && (hare->next)->next)
	{
		tortoise = tortoise->next;
		hare = (hare->next)->next;
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (hare);
		}
	}
	return (NULL);
}
