#include <stdlib.h>
#include "binary_trees.h"

/**
 * reverse_bits - reverse bits below the most-significant non-zero bit
 * @n: the number to reverse
 *
 * Return: the reversed bits
 */
unsigned long int reverse_bits(unsigned long int n)
{
	unsigned long int reversed = 0;

	while (n)
	{
		reversed <<= 1;
		reversed += n % 2;
		n >>= 1;
	}
	return (reversed);
}

/**
 * heap_size - calculate the size of a heap
 * @root: a pointer to the root
 *
 * Return: the size of the heap
 */
size_t heap_size(const heap_t *root)
{
	if (root)
		return (heap_size(root->left) + heap_size(root->right) + 1);
	return (0);
}

/**
 * heap_insert_ - insert a value into a max-heap (helper)
 * @root: the address of a pointer to the root
 * @node: a pointer to the node to insert
 * @parent: a pointer to the parent node
 * @path: the path to the insertion point
 *
 * Return: a pointer to the inserted node
 */
heap_t *heap_insert_(heap_t **root, heap_t *node, heap_t *parent, size_t path)
{
	if (path < 2)
	{
		*root = node;
		node->parent = parent;
	}
	else if (path % 2)
	{
		node = heap_insert_(&(*root)->right, node, *root, path >> 1);
	}
	else
	{
		node = heap_insert_(&(*root)->left, node, *root, path >> 1);
	}

	if (node->n > (*root)->n)
	{
		(*root)->n ^= node->n;
		node->n ^= (*root)->n;
		(*root)->n ^= node->n;
		node = *root;
	}
	return (node);
}

/**
 * heap_insert - insert a value into a max-heap
 * @root: the address of a pointer to the root
 * @value: the value to insert
 *
 * Return: If root is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL, *parent = NULL;
	size_t path = 0;

	if (!root)
		return (NULL);

	if (*root)
		parent = (*root)->parent;

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	path = reverse_bits(((heap_size(*root) + 1) << 1) + 1) >> 1;

	return (heap_insert_(root, node, parent, path));
}
