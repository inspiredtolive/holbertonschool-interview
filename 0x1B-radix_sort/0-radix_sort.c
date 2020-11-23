#include "sort.h"

/**
 * rds - Radix sorts an array of ints.
 * @arr: The array to sort.
 * @size: The size of the array.
 * @sd: The significant digit.
 */
void rds(int *arr, int size, int sd)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = {0};

	for (i = 0; i < size; i++)
		count[(arr[i] / sd) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / sd) % 10] - 1] = arr[i];
		count[(arr[i] / sd) % 10]--;
	}
	for (i = 0; i < size; i++)
		arr[i] = output[i];
	free(output);
}

/**
 * radix_sort - Radix sorts an array of ints (ascending).
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int sd, max;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	for (sd = 1; max / sd > 0; sd *= 10)
	{
		rds(array, size, sd);
		print_array(array, size);
	}
}

/**
 * find_max - Finds the max int in array of positive integers.
 * @array: The array to search.
 * @size: The size of the array.
 * Return: The max int.
 */
int find_max(int *array, size_t size)
{
	register uint i;
	register int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
