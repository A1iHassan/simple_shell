#include "shell.h"

/**
 * _strspn - get a length of initial segment matching
 * @s: the string
 * @accept: number of bytes
 *
 * Return: fi
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int fi, fj;

	for (fi = 0; s[fi] != '\0'; fi++)
	{
		for (fj = 0; accept[fj] != s[fi]; fj++)
		{
			if (accept[fj] == '\0')
				return (fi);
		}
	}
	return (fi);
}
