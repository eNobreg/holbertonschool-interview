#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *multiply(unsigned int len_first, unsigned int len_second,
				unsigned int res_len, char *first, char *second, char *results);

int checkDigit(char *digit);
int _putchar(char c);
int _strLen(char *string);
void print_error(void);

#endif
