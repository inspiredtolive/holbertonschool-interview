#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge.
 * @level:  The level to draw.
 */
void menger(int level)
{
	int c, r, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (c = 0; c < size; c++)
		{
			for (r = 0; r < size; r++)
				printf("%c", get_char(c, r));
			printf("\n");
		}
	}
}

/**
 * get_char - Gets a Menger Sponge char.
 * @c: The column of the char to get.
 * @r: The row of the char to get.
 * Return: '#' or ' '
 */
char get_char(int c, int r)
{
	for (; c && r; c /= 3, r /= 3)
		if (c % 3 == 1 && r % 3 == 1)
			return (' ');
	return ('#');
}
