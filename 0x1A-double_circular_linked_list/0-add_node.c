#include "list.h"
#include "string.h"

/**
 * create_node - Creates a node.
 * @str: The string to store in the node.
 * Return: A pointer to the created node or (NULL).
 */
List *create_node(char *str)
{
	List *newNode;

	newNode = malloc(sizeof(List));
	if (!newNode)
	{
		return (NULL);
	}
	newNode->str = strdup(str);
	if (!newNode->str)
	{
		free(newNode);
		return (NULL);
	}
	return (newNode);
}

/**
 * add_node - Adds a node to a double circular linked list.
 * @list: A double pointer to the head of the list.
 * @str: The string to store to the new node.
 * @begin: A flag to determine whether or not to add at the end of the list.
 * Return: The new node or (NULL).
 */
List *add_node(List **list, char *str, int begin)
{
	List *head, *newNode;

	if (!list || !str)
	{
		return (NULL);
	}
	newNode = create_node(str);
	if (!newNode)
	{
		return (NULL);
	}
	if (!*list)
	{
		*list = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return (newNode);
	}
	head = *list;
	newNode->next = head;
	newNode->prev = head->prev;
	head->prev->next = newNode;
	head->prev = newNode;
	if (begin)
	{
		*list = newNode;
	}
	return (newNode);
}

/**
 * add_node_end - Adds a new node to end of a double circular linked list.
 * @list: A double pointer to the head of the list.
 * @str: The string to store to the new node.
 * Return: A pointer to the new node or (NULL).
 */
List *add_node_end(List **list, char *str)
{
	return (add_node(list, str, 0));
}

/**
 * add_node_begin - Adds a node to begining of list.
 * @list: A double ptr to head of list.
 * @str: The string to store to the new node.
 * Return: A pointer to the new node or (NULL).
 */
List *add_node_begin(List **list, char *str)
{
	return (add_node(list, str, 1));
}
