#include "shell.h"
#include <sys/stat.h>
#include <string.h>

char *execute(char *command) {
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path) {
		path_copy = _strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL) {
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			if (!file_path) {
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);

			if (stat(file_path, &buffer) == 0) {
				free(path_copy);
				return (file_path);
			} else {
				free(file_path); 
				path_token = strtok(NULL, ":");
			}
		}

		free(path_copy);
		if (stat(command, &buffer) == 0) {
			return (command);
		} 


		return NULL;
	}

	return NULL;
}

