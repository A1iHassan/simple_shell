#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * _strdup - copies a given string to a newly allocated memory
 * @str: the given string
 * Return: a value of type char *
 */

char *_strdup(const char *str)
{
	int i = 0;
	char *a;

	if (str == NULL)
		return (NULL);

	a = malloc(sizeof(const char) * _strlen(str) + 1);

	if (a == NULL)
		return (0);

	while (*str)
	{
		a[i] = *str;
		i++;
		str++;
	}
	a[i] = '\0';
	return (a);
}
