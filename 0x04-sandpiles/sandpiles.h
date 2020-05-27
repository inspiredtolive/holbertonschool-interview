#ifndef SANDPILE_H
#define SANDPILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_grid(int grid[3][3]);
void add_matrix(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void collapse(int grid[3][3], int i, int j);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
