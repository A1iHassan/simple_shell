#include "shell.h"

/**
 * _setenv - adds a new enviroment variable to the environ
 * @var: variable name
 * @val: variable value
*/

void _setenv(char *var, char *val)
{

	if (setenv(var, val, 1) != 0)
	{
		perror("setenv");
	}
}
