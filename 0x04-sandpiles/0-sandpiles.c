#include "sandpiles.h"

/**
 * print_grid - prints a matrix
 * @grid: 3x3 matrix
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_matrix - adds 2 matrixes together
 * @grid1: 3x3 matrix
 * @grid2: 3x3 matrix
 */
void add_matrix(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * is_stable - checks to see if a matrix is stable (all values must
 * be between 0 and 3)
 * @grid: 3x3 matrix
 * Return: true or false
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * collapse - collapses a sandpile at a given index
 * @grid: input grid
 * @i: input row
 * @j: input col
 */
void collapse(int grid[3][3], int i, int j)
{
	int r, x, y;
	int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	for (r = 0; r < 4; r++)
	{
		x = i + directions[r][0];
		y = j + directions[r][1];
		if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
			grid[x][y] += 1;
	}
	grid[i][j] -= 4;
}

/**
 * sandpiles_sum - adds two matrixes and balances them out until they
 * are stable
 * @grid1: 3x3 matrix
 * @grid2: 3x3 matrix
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int c[3][3];
	int i, j, stable = 0;

	add_matrix(grid1, grid2);
	while (1)
	{
		stable = is_stable(grid1);
		if (!stable)
		{
			printf("=\n");
			print_grid(grid1);
			memcpy(c, grid1, 3 * 3 * sizeof(int));
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					if (grid1[i][j] > 3)
						collapse(c, i, j);
			memcpy(grid1, c, 3 * 3 * sizeof(int));
		} else
			break;
	}
}
