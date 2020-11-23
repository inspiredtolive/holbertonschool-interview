#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* print funcs */
void print_array(const int *array, size_t size);

/* sorting algos */
void radix_sort(int *array, size_t size);

/* helpers */
int find_max(int *array, size_t size);
void rds(int *arr, int size, int sd);

#endif
