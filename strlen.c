#include "shell.h"

/**
 * _strlen - bla
 * @s: bla
 * Return: bla
 */

size_t _strlen(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
