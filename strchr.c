#include "shell.h"

/**
 * _strchr - returns the pointer of a wanted char
 * @s: given string
 * @c:wanted char
 * Rerurn: index of wanted char
*/
char *_strchr(char *s, char c)
 {
	char *a = s;
	while (*a)
	{
		if (*a == c)
			return (a);
		a++;
	}
	return ('\0');
 }