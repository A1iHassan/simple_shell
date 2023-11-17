#include "shell.h"

/**
 * main - program entry for simple shell
 * @argc: number of input arguments
 * @argv: vector of input arguments
 * @envp: vector of enviroment variavles
 * Return: exit status
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t charac;

	(void)argc;
	(void)argv;
	while (1)
	{

		if (isatty(0))
		{
			_print("$ ");
		}
		charac = getline(&line, &n, stdin);
		if (charac == -1)
		{
			if (isatty(0))
			{
				_print("\n"); }
			break; }
		if (count(line) == 0)
			continue;
		line[_strlen(line) - 1] = '\0';
		while (line)
		{
			if (*line == '#')
				*line = '\0';
		}
		_print("");
		if (built_in(line) == 1)
			continue;
		if (comp_built(line) == 1)
			continue;
		if (more_built(line, envp) == 1)
			continue;
		}

	free(line);
	return (0); }
