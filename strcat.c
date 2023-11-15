#include "shell.h"

/**
 * _strcat - concatenates toe strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to the new string
 */
char *_strcat(char *s1, char *s2)
{
	char *a = NULL;
	int i = 0, j = 0;
	int k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = _strlen(s1);
	j = _strlen(s2);

	a = malloc(sizeof(char) * (i + j));

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
	return (a);
}
