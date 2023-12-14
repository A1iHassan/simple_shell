#include "shell.h"
#include<string.h>
/**
 * main - program entry for simple shell
 * @argc: number of input arguments
 * @argv: vector of input arguments
 * @envp: vector of enviroment variavles
 * Return: exit status
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL, *token = NULL, *temp;
	size_t n = 0;
	ssize_t charac;
	int i, status = 0, *stptr = &status;

	(void)argc;
	(void)argv;
	while (1)
	{
		if (isatty(0))
			_print("$ ");
		charac = getline(&line, &n, stdin);
		if (charac == -1)
		{
			if (isatty(0))
				_print("\n");
			break; }
		if (count(line) == 0)
			continue;
		i = 0;
		while (line[i])
		{
			if (line[i] == '#' && (line[i - 1] == '"' || line[i - 1] == ' '))
			{
				line[i] = '\0';
				break; }
			else if (line[i] == '\n')
			{
				line[i] = '\0';
				break; }
			i++; }
			i = 0;
		temp = line;
		printf("%s\n", temp);
		token = strtok(temp, ";");
		while (token)
		{
			printf("%s\n", token);
			i += _strlen(token);
			temp += i + 1;
			if (_strlen(token) == 0 || _echo(token, stptr) == 1)
			{
					continue; }
			if (built_in(token, stptr) == 1 || comp_built(token, stptr) == 1)
			{
					continue; }
			if (more_built(token, envp, stptr) == 1)
			{
					continue; }
			token = strtok(temp, ";"); } }
	free(line);
	return (0); }
