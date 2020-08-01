#include "binary_trees.h"

/**
 * recursiveConvert - A recursively converts an array to an AVL tree.
 * @array: The sorted int array.
 * @begin: The beginning index.
 * @end: The last index.
 * @parent: A pointer to the parent node.
 * Return: The newly created AVL node.
 */
avl_t *recursiveConvert(int *array, int begin, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (begin > end)
		return (NULL);
	mid = (begin + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);
	node->n = array[mid];
	node->parent = parent;
	node->left = _sorted_array_to_avl(array, begin, mid - 1, new);
	node->right = _sorted_array_to_avl(array, mid + 1, end, new);
	return (new);
}

/**
 * sorted_array_to_avl - Validates array and converts the array to an AVL tree.
 * @array: The sorted int array.
 * @size: The size of the array.
 * Return: The pointer to the root node or (NULL) if failed.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array)
		return (NULL);
	return (recursiveConvert(array, 0, size - 1, NULL));
}
