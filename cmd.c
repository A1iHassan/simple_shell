#include "shell.h"

/**
 * execmd - a caller function for execve
 * @argv: array of command and its argument
 */
int execmd(char **argv)
{
	char *command = argv[0], *cmd = execute(command);
	extern char **environ;
	pid_t process;
	int pr;

	if (cmd)
	{
		process = fork();
		if (process == 0)
		{
			if (argv)
			{
				if (execve(cmd, argv, environ) == -1)
				{
					perror("execve");
					write(2, "./hsh: 1: ", 10);
					write(2, command, strlen(command));
					write(2, ": not found\n", 12);
			/**		free(cmd);
					// _free(argv, _strlen_(argv));
					// exit(127);*/
					return (127);
				}
			free(cmd);
			}
		}
		else if (process < 0)
		{
		/*	// free(cmd);
			// _free(argv, _strlen_(argv));*/
			perror("FORK FAILED");
/*			// exit(EXIT_FAILURE);*/
			return (1);
		}
/*		// free(cmd);
		// _free(argv, _strlen_(argv));*/
		wait(&pr);
	}
	else
	{
		write(2, "./hsh: 1: ", 10);
		write(2, command, strlen(command));
		write(2, ": not found\n", 12);
		free(cmd);
/**		// free(cmd);
		// _free(argv, _strlen_(argv));
		// exit(127);*/
		return (127);
	}
	if (cmd != argv[0])
		free(cmd);
	return (0);
}
