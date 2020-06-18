#include "palindrome.h"

/**
 * is_palindrome - Checks if an integer is a palindrome.
 * @n: The integer to check.
 * Return: True if the integer is a palindrome or false.
 */
int is_palindrome(unsigned long n)
{
	unsigned int rev = 0;

	if (n && !(n % 10))
		return (0);
	for (; n > rev; n /= 10)
		rev = (rev * 10) + n % 10;
	return (n == rev || n == (rev / 10));
}
