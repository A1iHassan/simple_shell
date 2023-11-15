#include "shell.h"

/**
 * _unsetenv - removes a variable from the environ vector
 * @var: variable name
 */

void _unsetenv(char *var)
{
	if (unsetenv(var) != 0)
	{
		perror("unsetenv");
	}
}
