#include "shell.h"
/**
 * _strlen_ - calculates the length of a two dimentional array
 * @s: array pointer
 * Return: array length
 */
size_t _strlen_(char **s)
{
	char **a = s;
	size_t i = 0;

	while (a[i])
	{
		i++;
	}
	return (i);
}
