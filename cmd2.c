#include "shell.h"

int execmd(char **argv, char **envp) {
	char *command = argv[0], *cmd = execute(command);
	pid_t process;
	int status;

	if (cmd == NULL) {
		write(2, "./hsh: 1: ", 10);
		write(2, command, _strlen(command));
		write(2,": not found\n", 12);	
		exit(127);
	} else if (access(cmd, X_OK) != 0) {
		perror("Permission denied");
		free(cmd);
		return(2);
	}

	process = fork();

	if (process == 0) {

			if (execve(cmd, argv, envp) == -1) {
				perror("execve");
				free(cmd);
				exit(EXIT_FAILURE);
			}
			
	
	} else if (process < 0) {
		perror("FORK FAILED");
		free(cmd);
		return (1);
	}

	waitpid(process, &status, 0);
	if (cmd != argv[0])
	{
		free(cmd);

	}
	return (0);
}
