#include "sort.h"

/**
 * heap_sort - Heap sorts an array of integers.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Creates a heap from an array.
 * @arr: The array to create the heap from.
 * @n: The size of the heap.
 * @i: The index of the root.
 * @size: The length of the array.
 */
void heapify(int *arr, int n, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, size);
		heapify(arr, n, max, size);
	}
}

/**
 * swap - Swaps two integers.
 * @a: The integer to swap with b.
 * @b: The integer to swap with a.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
