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
	int i = 0, arr_count = 0;
	char **a = NULL;
	(void)argc, argv, envp;

	while (1)
	{
start:
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
			goto start;
		line[_strlen(line) - 1] = '\0';
		_print("");
		if (built_in(line) == 1)
			goto start;
		else
		{
			a = tokenize(line);
			arr_count = _strlen_(a);
			
			execmd(a);
			while (a[i])
			{
				free(a[i]);
				i++; }
			free(a[i]);
			free(a);
			i = 0;
			}
		}
	free(line);
	return (0); }
