#include "shell.h"

/**
 * _envp_ - display the enviroment variables of the current process
 */
void _envp_(char **envp)
{
	char **extr;

	for (extr = envp; *extr != NULL; extr++)
	{
		_print(*extr);
		_print("\n");
	}
}

