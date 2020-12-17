#include "holberton.h"

/**
 * wildcmp - Checks if two strings match including a wildcard(*).
 * @s1: The string to match with s2.
 * @s2: The string to match with s1, can contain wildcard(*).
 * Return: If match true(1), else false(0).
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
