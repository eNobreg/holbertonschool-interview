#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);
int check_stability(int grid1[3][3]);
void add(int grind1[3][3], int grid2[3][3]);

#endif
