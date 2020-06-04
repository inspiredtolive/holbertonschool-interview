#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent node.
 * @value: The value to store in the new node.
 *
 * Return: The pointer to the new node or (NULL).
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = calloc(1, sizeof(*node));

	if (node)
	{
		node->n = value;
		node->parent = parent;
	}
	return (node);
}
