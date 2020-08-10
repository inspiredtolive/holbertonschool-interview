#include "search.h"

/**
 * searchList - Searches a value in a list.
 * @prev: The pointer to the node to start searching.
 * @exp: The pointer to the node to end searching.
 * @value: The value to search for
 * Return: The pointer to the node with the value or (NULL).
 */
skiplist_t *searchList(skiplist_t *prev, skiplist_t *exp, int value)
{
	printf("Value found between indexes [%li] and [%li]\n",
			prev->index, exp->index);
	while (prev != exp->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip - Searches a value in a skip list.
 * @list: A pointer to the head of the list.
 * @value: The value to search for.
 * Return: The pointer to the node with the value or (NULL).
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *exp;

	if (!list)
		return (NULL);
	exp = list;
	while (exp)
	{
		prev = exp;
		if (exp->express)
			exp = exp->express;
		else
		{
			while (exp->next)
				exp = exp->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n", exp->index, exp->n);
		if (exp->n >= value)
			return (searchList(prev, exp, value));
	}
	return (searchList(prev, exp, value));
}
