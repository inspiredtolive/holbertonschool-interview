#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks is tree an AVL Tree.
 * @tree: The pointer to the root node.
 * Return: True(1) or False(0).
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}

/**
 * is_avl - Recursively checks if tree an AVL Tree.
 * @tree: The pointer to current root.
 * @min: The current min val.
 * @max: The current max val.
 * @height: The int pointer to the height of this tree.
 * Return: True(1) or False(0).
 */
int is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!is_avl(tree->left, min, tree->n, &h1) ||
		!is_avl(tree->right, tree->n, max, &h2))
		return (0);
	*height = MAX(h1, h2) + 1;
	return (ABS(h1 - h2) <= 1);
}
