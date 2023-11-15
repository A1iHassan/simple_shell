#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>

/**
 * execute - parses the input line to be passed to the execmd function
 * @command: input line to be parsed
 * Return: a pointer to the new command string
 */
char *execute(char *command)
{
	char *path = getenv("PATH");
	struct stat buffer;
	char *copy, *token, *fold, *temp1, *temp2;
	int dir;
	int len;

	if (path)
	{
		copy = _strdup(path);
		token = strtok(copy, ":");

		len = _strlen(command);

		while (token != NULL)
		{
			dir = _strlen(token);
			temp1 = malloc(len + 1 + dir + 1);

			_strcpy(temp1, token);
			temp2 = _strcat(temp1, "/");
			fold = _strcat(temp2, command);
			free(temp1);
			free(temp2);

			if (stat(fold, &buffer) == 0)
			{
				free(copy);
				return (fold); }
			free(fold);
			token = strtok(NULL, ":"); }
		free(copy); }

	if (stat(command, &buffer) == 0)
	{
		return (command); }

	return (NULL); }

