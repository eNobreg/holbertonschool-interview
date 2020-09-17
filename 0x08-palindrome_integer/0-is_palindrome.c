#include "palindrome.h"

/**
 * is_palindrome - Function to check if an integer is a palindrome
 * @n: The integer to check
 * Return: 1  if it is a palindrome, 0 if it is not
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp = 0;
	unsigned long rev = 0;
	unsigned long saved = n;

	while (n > 0)
	{
		temp =  n % 10;
		rev = rev * 10 + temp;
		n /= 10;
	}

	if (saved == rev)
		return (1);
	return (0);
}
