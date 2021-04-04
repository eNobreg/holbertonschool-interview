#include "holberton.h"

/**
 * wildcmp - Compare two strings if one includes wildcards
 * @s1: The initial string to compare
 * @s2: The wildcard string to compare to
 * Return: 1 on success if they're identical, 0 on failure
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings are null they're identical */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}
	/* If s1 is different return 0, else check next char */

	return (*s1 != *s2 ? 0 : wildcmp(s1 + 1, s2 + 1));
}
