#include "shell.h"

/**
 * _envp_ - display the enviroment variables of the current process
 */
void _envp_(void)
{
	extern char **environ;
	char **extr;

	for (extr = environ; *extr != NULL; extr++)
	{
		_print(*extr);
		_print("\n");
	}
}

