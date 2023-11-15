#include "shell.h"

/**
 * handle_set - handels the input for the setenv function
 * @args: array of srguments to be processed
 */

void handle_set(char **args)
{
	char *var;
	char *val;

	if (_strlen_(args) < 3)
	{
		write(STDERR_FILENO, "fail set\n", 9);
	} else if (_strlen_(args) > 3)
	{
		write(STDERR_FILENO, "u enter more than 3\n", 19);
	} else
	{
		var = args[1];
		val = args[2];
		if (setenv(var, val, 1) != 0)
		{
			perror("setenv");
		}
	}
}
