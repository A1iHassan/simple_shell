#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * execute - parses the input line to be passed to the execmd function
 * @command: input line to be parsed
 * Return: a pointer to the new command string
 */
char *execute(char *command)
{
	char *path = getenv("PATH");
	struct stat buffer;
	char *copy = NULL, *token = NULL, *fold = NULL,
  *temp1 = NULL, *temp2 = NULL;
	int dir = 0;
	int len = 0;

	if (path)
	{
		copy = _strdup(path);
		token = strtok(copy, ":");

		len = strlen(command);

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

#include "shell.h"

/**
 * execmd - a caller function for execve
 * @argv: array of command and its argument
 */
int execmd(char **argv, char **env, int proc)
{
	char *command = argv[0], *cmd = execute(command),
  num = '0' + proc;
	pid_t process = 0;
	int pr = 0;

	if (cmd)
	{
		process = fork();
		if (process == 0)
		{
			if (argv)
			{
				if (execve(cmd, argv, env) == -1)
				{
					perror("execve");
					write(2, "./hsh: ", 10);
          write(2, &num, 1);
          write(2, ": ", 2);
					write(2, command, strlen(command));
					write(2, ": not found\n", 12);
          return (127); } }
		}
		else if (process < 0)
		{
			perror("FORK FAILED");
      return (2); }
		wait(&pr); }
	else
	{
		write(2, "./hsh: 1: ", 10);
		write(2, command, strlen(command));
		write(2, ": not found\n", 12);
		free(cmd);
    return (127); }
	if (cmd != argv[0])
		free(cmd);
  return (0); }
