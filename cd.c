#include "shell.h"

/**
 * _cd - changes the current working directory to another desired ones
*/

void _cd(void)
{
	char *cm = getcwd(NULL, 0);

	if (cm == NULL)
	{
		perror("getcwd");
		return;
	}

	setenv("PWD", cm, 1);
	free(cm);
}
