#include "regex.h"

/**
 * regex_match - Checks if regex pattern matches the string.
 * @s: The string to match.
 * @p: The regex pattern.
 * Return: If match (1) else (0)
 */
int regex_match(char const *s, char const *p)
{
	if (!*s)
		return (!*p || (p[1] == '*' && regex_match(s, p + 2)));
	if (p[1] == '*')
		return ((*p == '.' || *s == *p)
			 ? (regex_match(s + 1, p) || regex_match(s, p + 2))
			 : (regex_match(s, p + 2)));
	return ((*p == '.' || *p == *s) && regex_match(s + 1, p + 1));
}
