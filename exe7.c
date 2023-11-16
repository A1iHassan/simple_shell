#include "shell.h"
#include <sys/stat.h>
#include <string.h>

char *execute(char *command) {
	char *path, *copy, *token, *fold;
	int command_len;
	int dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path) {
		copy = _strdup(path);
		command_len = strlen(command);
		token = strtok(copy, ":");

		while (token != NULL) {
			dir_len = strlen(token);
			fold = malloc(command_len + 1 + dir_len + 1);

			if (!path) {
				perror("faild");
				exit(EXIT_FAILURE);
			}

			strcpy(fold, token);
			strcat(fold, "/");
			strcat(fold, command);

			if (stat(fold, &buffer) == 0) {
				free(copy);
				return (fold);
			} else {
				free(fold); 
				token = strtok(NULL, ":");
			}
		}

		free(copy);
		if (stat(command, &buffer) == 0) {
			return (command);
		} 


		return (NULL);
	}

	return (NULL);
}

