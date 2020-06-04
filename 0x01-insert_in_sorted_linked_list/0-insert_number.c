#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a number into a sorted linked list
 * @head: the address of a pointer to the head of the lsit
 * @number: the number to insert into the list
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = head ? malloc(sizeof(*node)) : NULL;

	if (node)
	{
		node->n = number;
		while (*head && number > (*head)->n)
			head = &(*head)->next;
		node->next = *head;
		*head = node;
	}
	return (node);
}
