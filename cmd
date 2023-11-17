#include "shell.h"

/**
 * execmd - a caller function for execve
 * @argv: array of command and its argument
 */
int execmd(char **argv, char **envp)
{
	char *command = argv[0], *cmd = execute(command);
	pid_t process;
	int status;

	if (cmd == NULL)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": not found\n", 12);
		free(cmd);
	
		return (127);	}
	else if (access(cmd, X_OK) != 0)
		{
			write(STDERR_FILENO, "found it", 8);
			return (2); }

		process = fork();
		if (process == 0)
		{
			if (argv)
			{
				if (execve(cmd, argv, envp) == -1)
				{
					perror("execve");
					free(cmd);
					exit(EXIT_FAILURE);
				}
			}

		}
		else if (process < 0)
		{
			perror("FORK FAILED");
			return (1);
		}
		wait(&status);
	return (0);
}
