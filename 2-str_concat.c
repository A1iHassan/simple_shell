#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * str_concat - concatenates to given strings
 * @s1: string 1
 * @s2: string 2
 * Return: a value of type char *
 */

char *str_concat(char *s1, char *s2)
{
	char *a;
	int i, j;
	int k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = _strlen(s1);
	j = _strlen(s2);

	a = malloc(sizeof(char) * (i + j + 1));

	if (a == 0)
		return (NULL);
	while (*s1)
	{
		a[k] = *s1;
		k++;
		s1++;
	}
	while (*s2)
	{
		a[k] = *s2;
		k++;
		s2++;
	}
	a[k] = '\0';
	return (a);
}
