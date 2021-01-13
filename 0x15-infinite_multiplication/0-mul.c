#include "holberton.h"

/**
 * main - Driver
 * @argc: Amount of arguments passed in
 * @argv: Arguments passed from command line
 * Return: 0 or nothing depend on error
 */
int main(int argc, char *argv[])
{

	char *results = NULL;
	unsigned int len_first, len_second, len_result = 0;
	unsigned int count = 0;

	if (argc != 3)
		print_error();

	len_first = _strLen(argv[1]);
	len_second = _strLen(argv[2]);
	len_result = len_first + len_second;

	results = malloc(len_result * sizeof(char));
	if (results == NULL)
		print_error();

	if (!checkDigit(argv[1]) || !checkDigit(argv[2]))
	{
		free(results);
		print_error();
	}

	while (count < len_result * sizeof(char))
	{
		results[count] = 0;
		count += 1;
	}

	multiply(len_first, len_second, len_result, argv[1], argv[2], results);
	_putchar('\n');

	free(results);
	return (0);
}
/**
 * multiply - Main function for infinite multiplication
 * @len_first: Length of first number string
 * @len_second: Length of second number string
 * @res_len: Length of result string
 * @first: The first number
 * @second: The second number
 * @results: The resulting string
 * Return: The sum of two numbers or nothing
 */
char *multiply(unsigned int len_first, unsigned int len_second,
			   unsigned int res_len, char *first, char *second, char *results)
{
	int i, j, carry, num1, num2, sum = 0, i_f = 0;
	int i_s = 0;

	if (len_first == 0 || len_second == 0)
	{
		return ("0");
	}
	for (i = len_first - 1; i >= 0; i--)
	{
		carry = 0;
		num1 = first[i] - '0';
		i_s = 0;

		for (j = len_second - 1; j >= 0; j--)
		{
			num2 = second[j] - '0';

			sum = num1 * num2 + results[i_f + i_s] + carry;
			carry = sum / 10;
			results[i_f + i_s] = sum % 10;
			i_s++;
		}
		if (carry > 0)
			results[i_f + i_s] += carry;
		i_f++;
	}

	i = res_len;
	while (i >= 0 && results[i] == 0)
		i--;

	if (i == -1)
	{
		_putchar('0');
		return ("0");
	}

	while (i >= 0)
		_putchar(results[i--] + '0');
	return (results);
}

/**
 * checkDigit - Checks a string for any char that is not a digit
 * @digit: String to check
 * Return: 1 if string passes, 0 on failure
 */
int checkDigit(char *digit)
{
	int i = 0;

	while (digit[i] != '\0')
	{
		if (digit[i] < 48 || digit[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * _strLen - Accepts a string and returns the length
 * @string: String to measure
 * Return: The length of the string
 */
int _strLen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * print_error - prints the error message and exits
 * Return: Nothing
 */
void print_error(void)
{
	int i = 0;
	char *msg = "Error";

	while (msg[i] != '\0')
	{
		_putchar(msg[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
}
