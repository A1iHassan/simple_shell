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
	/*int i = 0;*/
<<<<<<< HEAD
	int arr_count = 0, status = 0;
=======
/*	int arr_count = 0;*/
>>>>>>> 7eea9adc676d629ac8f99b1776413809c7ee8bd7
	char **a = NULL;
	(void)argc;
	(void)argv;
	(void)envp;

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
/**		arr_count = _strlen_(a);*/
			
<<<<<<< HEAD
			status = execmd(a);
			_free(a, arr_count);
=======
			execmd(a);
		free(a);

>>>>>>> 7eea9adc676d629ac8f99b1776413809c7ee8bd7
			}
		}

	free(line);
	return (status); }
