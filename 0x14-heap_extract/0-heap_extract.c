#include "binary_trees.h"

/**
 * binary_tree_size - Gets the size of a binary tree.
 * @tree: The tree to  measure.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * free_last - Removes the last node of the tree.
 * @root: The root of the tree.
 * Return: The value of the deleted node.
 */
int free_last(heap_t **root)
{
	int size, end = 0, bits, flag = 0;
	heap_t *tmp, *target;

	tmp = *root;
	size = binary_tree_size(*root);
	for (bits = sizeof(size) * 8 - 1; bits >= 0; bits--)
	{
		if (bits == 0)
		{
			if ((size >> bits) & 1)
			{
				target = tmp->right;
				tmp->right = NULL;
			}
			else
			{
				target = tmp->left;
				tmp->left = NULL;
			}
			end = target->n;
			free(target);
		}
		if ((size >> bits) & 1)
		{
			if (flag)
				tmp = tmp->right;
			flag = 1;
		}
		else if (flag)
			tmp = tmp->left;
	}
	return (end);
}

/**
 * xor_swap - Swaps two ints.
 * @a: A pointer to an int to swap with b.
 * @b: A pointer to an int t oswap with a.
 */
void xor_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * bubble_down - Bubble-downs the node to the correct position.n
 * @node: The node to insert.
 */
void bubble_down(heap_t *node)
{
	int max;

	max = node->n;
	if (node->left && node->left->n > max)
		max = node->left->n;
	if (node->right && node->right->n > max)
		max = node->right->n;
	if (max != node->n)
	{
		if (max == node->left->n)
		{
			xor_swap(&node->n, &node->left->n);
			bubble_down(node->left);
		}
		else
		{
			xor_swap(&node->n, &node->right->n);
			bubble_down(node->right);
		}
	}
}

/**
 * heap_extract - Extracts the root node.
 * @root: A double pointer to the root of the tree.
 * Return: The value of the root node.
 */
int heap_extract(heap_t **root)
{
	int res;

	if (!root || !*root)
		return (0);
	res = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		root = NULL;
		return (res);
	}
	(*root)->n = free_last(root);
	bubble_down(*root);
	return (res);
}
