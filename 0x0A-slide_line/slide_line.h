#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

int slide_line(int *line, size_t size, int direction);
int count_digits(int* line, int direction, int size);

#endif