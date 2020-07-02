#include "slide_line.h"

/**
 * slide_line - Slides a line either left or right.
 * @line: The line array.
 * @size: The size of the array.
 * @direction: The direction to slide in.
 * Return: If successful (1) or (0).
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	direction == SLIDE_LEFT ? slide_left(line, size)
		: slide_right(line, size);
	return (1);
}

/**
 * slide_left - Slides the line to the left.
 * @line: The line array.
 * @size: The size of the array.
 */
void slide_left(int *line, size_t size)
{
	int i = 0, j, prev = 0, curr;

	for (j = 0; j < (int)size; j++)
	{
		curr = line[j];
		if (!curr)
			continue;
		if (!prev)
			prev = curr;
		else if (prev == curr)
		{
			line[i++] = curr << 1;
			prev = 0;
		} else
		{
			line[i++] = prev;
			prev = curr;
		}
	}
	if (prev)
		line[i++] = prev;
	while (i < (int)size)
		line[i++] = 0;
}

/**
 * slide_right - Slides a line to the right.
 * @line: The line array.
 * @size: The size of the array.
 */
void slide_right(int *line, size_t size)
{
	int prev = 0, i = size - 1, j, curr;

	for (j = size - 1; j >= 0; j--)
	{
		curr = line[j];
		if (!curr)
			continue;
		if (!prev)
			prev = curr;
		else if (prev == curr)
		{
			line[i--] = curr << 1;
			prev = 0;
		} else
		{
			line[i--] = prev;
			prev = curr;
		}
	}
	if (prev)
		line[i--] = prev;
	while (i >= 0)
		line[i--] = 0;
}
