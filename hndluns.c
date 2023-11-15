#include "shell.h"
/**
 * handel_unset - handel unsetenv
 * @args: argument
 */
void handel_unset(char **args)
{
	char *var;

	if (_strlen_(args) < 2)
	{
		write(STDERR_FILENO, "fail unset\n", 11);
	}
	else if (_strlen_(args) > 2)
	{
		write(STDERR_FILENO, "u enter more than 2 args\n", 23);
	}
	else
	{
		var = args[1];
		_unsetenv(var);
	}
}
